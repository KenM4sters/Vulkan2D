#include "SwapChain.hpp"
#include <iostream>

namespace mt 
{
SwapChain::SwapChain(const PhysicalDevice& physicalDevice, const LogicalDevice& logicalDevice, VkExtent2D extent)
    : mPhysicalDevice{physicalDevice}, mLogicalDevice{logicalDevice}, mWindowExtent{extent}
{
    Init();
}   

SwapChain::SwapChain(const PhysicalDevice& physicalDevice, const LogicalDevice& logicalDevice, VkExtent2D extent, std::shared_ptr<SwapChain>& previous)
    : mPhysicalDevice{physicalDevice}, mLogicalDevice{logicalDevice}, mWindowExtent{extent}, mPreviousSwapChain{previous}
{
    Init();
    mPreviousSwapChain = nullptr;
}

SwapChain::~SwapChain() 
{
    for (auto imageView : mSwapChainImageViews) 
    {
        vkDestroyImageView(mLogicalDevice.GetDevice(), imageView, nullptr);
    }
    mSwapChainImageViews.clear();

    if (mSwapChain != nullptr) 
    {
        vkDestroySwapchainKHR(mLogicalDevice.GetDevice(), mSwapChain, nullptr);
        mSwapChain = nullptr;
    }

    for (int i = 0; i < mDepthImages.size(); i++) 
    {
        vkDestroyImageView(mLogicalDevice.GetDevice(), mDepthImageViews[i], nullptr);
        vkDestroyImage(mLogicalDevice.GetDevice(), mDepthImages[i], nullptr);
        vkFreeMemory(mLogicalDevice.GetDevice(), mDepthImageMemorys[i], nullptr);
    }

    for (auto framebuffer : mSwapChainFramebuffers) 
    {
        vkDestroyFramebuffer(mLogicalDevice.GetDevice(), framebuffer, nullptr);
    }

    vkDestroyRenderPass(mLogicalDevice.GetDevice(), mRenderPass, nullptr);

    // cleanup synchronization objects
    for (size_t i = 0; i < FRAMES_IN_FLIGHT; i++) 
    {
        vkDestroySemaphore(mLogicalDevice.GetDevice(), mRenderFinishedSemaphores[i], nullptr);
        vkDestroySemaphore(mLogicalDevice.GetDevice(), mImageAvailableSemaphores[i], nullptr);
        vkDestroyFence(mLogicalDevice.GetDevice(), mInFlightFences[i], nullptr);
    }
}

void SwapChain::Init() 
{
    CreateSwapChain();
    CreateImageViews();
    CreateRenderPass();
    CreateDepthResources();
    CreateFramebuffers();
    CreateSyncObjects();
}

void SwapChain::CreateSwapChain() 
{
    SwapChainSupportDetails swapChainSupport = mPhysicalDevice.GetSwapChainSupport();

    VkSurfaceFormatKHR surfaceFormat = ChooseSwapSurfaceFormat(swapChainSupport.formats);
    VkPresentModeKHR presentMode = ChooseSwapPresentMode(swapChainSupport.presentModes);
    VkExtent2D extent = ChooseSwapExtent(swapChainSupport.capabilities);

    uint32_t imageCount = swapChainSupport.capabilities.minImageCount + 1;
    if (swapChainSupport.capabilities.maxImageCount > 0 &&
        imageCount > swapChainSupport.capabilities.maxImageCount) 
    {
        imageCount = swapChainSupport.capabilities.maxImageCount;
    }

    VkSwapchainCreateInfoKHR createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    createInfo.surface = mPhysicalDevice.GetSurface();

    createInfo.minImageCount = imageCount;
    createInfo.imageFormat = surfaceFormat.format;
    createInfo.imageColorSpace = surfaceFormat.colorSpace;
    createInfo.imageExtent = extent;
    createInfo.imageArrayLayers = 1;
    createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

    QueueFamilyIndices indices = mPhysicalDevice.GetQueueFamilyIndices();
    uint32_t queueFamilyIndices[] = {indices.graphicsFamily, indices.presentFamily};

    if (indices.graphicsFamily != indices.presentFamily) 
    {
        createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
        createInfo.queueFamilyIndexCount = 2;
        createInfo.pQueueFamilyIndices = queueFamilyIndices;
    } else {
        createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        createInfo.queueFamilyIndexCount = 0;      // Optional
        createInfo.pQueueFamilyIndices = nullptr;  // Optional
    }

    createInfo.preTransform = swapChainSupport.capabilities.currentTransform;
    createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;

    createInfo.presentMode = presentMode;
    createInfo.clipped = VK_TRUE;

    createInfo.oldSwapchain = mPreviousSwapChain == nullptr ? VK_NULL_HANDLE : mPreviousSwapChain->mSwapChain;

    if (vkCreateSwapchainKHR(mLogicalDevice.GetDevice(), &createInfo, nullptr, &mSwapChain) != VK_SUCCESS) 
    {
        throw std::runtime_error("failed to create swap chain!");
    }

    // we only specified a minimum number of images in the swap chain, so the implementation is
    // allowed to create a swap chain with more. That's why we'll first query the final number of
    // images with vkGetSwapchainImagesKHR, then resize the container and finally call it again to
    // retrieve the handles.
    vkGetSwapchainImagesKHR(mLogicalDevice.GetDevice(), mSwapChain, &imageCount, nullptr);
    mSwapChainImages.resize(imageCount);
    vkGetSwapchainImagesKHR(mLogicalDevice.GetDevice(), mSwapChain, &imageCount, mSwapChainImages.data());

    mSwapChainImageFormat = surfaceFormat.format;
    mSwapChainExtent = extent;
}

void SwapChain::CreateImageViews() 
{
  mSwapChainImageViews.resize(mSwapChainImages.size());
  for (size_t i = 0; i < mSwapChainImages.size(); i++) 
  {
        VkImageViewCreateInfo viewInfo{};
        viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        viewInfo.image = mSwapChainImages[i];
        viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        viewInfo.format = mSwapChainImageFormat;
        viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        viewInfo.subresourceRange.baseMipLevel = 0;
        viewInfo.subresourceRange.levelCount = 1;
        viewInfo.subresourceRange.baseArrayLayer = 0;
        viewInfo.subresourceRange.layerCount = 1;

        if (vkCreateImageView(mLogicalDevice.GetDevice(), &viewInfo, nullptr, &mSwapChainImageViews[i]) !=
            VK_SUCCESS) 
        {
            throw std::runtime_error("failed to create texture image view!");
        }
  }
}

void SwapChain::CreateDepthResources() 
{
    VkFormat depthFormat = FindDepthFormat();
    mSwapChainDepthFormat = depthFormat;
    VkExtent2D swapChainExtent = GetSwapChainExtent();

    mDepthImages.resize(GetImageCount());
    mDepthImageMemorys.resize(GetImageCount());
    mDepthImageViews.resize(GetImageCount());

    for (int i = 0; i < mDepthImages.size(); i++) 
    {
        VkImageCreateInfo imageInfo{};
        imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        imageInfo.imageType = VK_IMAGE_TYPE_2D;
        imageInfo.extent.width = swapChainExtent.width;
        imageInfo.extent.height = swapChainExtent.height;
        imageInfo.extent.depth = 1;
        imageInfo.mipLevels = 1;
        imageInfo.arrayLayers = 1;
        imageInfo.format = depthFormat;
        imageInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
        imageInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        imageInfo.usage = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
        imageInfo.samples = VK_SAMPLE_COUNT_1_BIT;
        imageInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        imageInfo.flags = 0;

        mLogicalDevice.CreateImageFromInfo(
            imageInfo,
            VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
            mDepthImages[i],
            mDepthImageMemorys[i]);

        VkImageViewCreateInfo viewInfo{};
        viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        viewInfo.image = mDepthImages[i];
        viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        viewInfo.format = depthFormat;
        viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
        viewInfo.subresourceRange.baseMipLevel = 0;
        viewInfo.subresourceRange.levelCount = 1;
        viewInfo.subresourceRange.baseArrayLayer = 0;
        viewInfo.subresourceRange.layerCount = 1;

        if (vkCreateImageView(mLogicalDevice.GetDevice(), &viewInfo, nullptr, &mDepthImageViews[i]) != VK_SUCCESS) 
        {
            throw std::runtime_error("failed to create texture image view!");
        }
    }
}

void SwapChain::CreateRenderPass() 
{
    VkAttachmentDescription depthAttachment{};
    depthAttachment.format = FindDepthFormat();
    depthAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
    depthAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    depthAttachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    depthAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    depthAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    depthAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    depthAttachment.finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

    VkAttachmentReference depthAttachmentRef{};
    depthAttachmentRef.attachment = 1;
    depthAttachmentRef.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

    VkAttachmentDescription colorAttachment = {};
    colorAttachment.format = GetSwapChainImageFormat();
    colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
    colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    VkAttachmentReference colorAttachmentRef = {};
    colorAttachmentRef.attachment = 0;
    colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass = {};
    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments = &colorAttachmentRef;
    subpass.pDepthStencilAttachment = &depthAttachmentRef;

    VkSubpassDependency dependency = {};
    dependency.dstSubpass = 0;
    dependency.dstAccessMask =
        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
    dependency.dstStageMask =
        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT | VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT;
    dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
    dependency.srcAccessMask = 0;
    dependency.srcStageMask =
        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT | VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT;

    std::array<VkAttachmentDescription, 2> attachments = {colorAttachment, depthAttachment};
    VkRenderPassCreateInfo renderPassInfo = {};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    renderPassInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
    renderPassInfo.pAttachments = attachments.data();
    renderPassInfo.subpassCount = 1;
    renderPassInfo.pSubpasses = &subpass;
    renderPassInfo.dependencyCount = 1;
    renderPassInfo.pDependencies = &dependency;

    if (vkCreateRenderPass(mLogicalDevice.GetDevice(), &renderPassInfo, nullptr, &mRenderPass) != VK_SUCCESS) 
    {
        throw std::runtime_error("failed to create render pass!");
    }
}

void SwapChain::CreateFramebuffers() 
{
    mSwapChainFramebuffers.resize(GetImageCount());
    for (size_t i = 0; i < GetImageCount(); i++) 
    {
        std::array<VkImageView, 2> attachments = {mSwapChainImageViews[i], mDepthImageViews[i]};

        VkExtent2D swapChainExtent = GetSwapChainExtent();
        VkFramebufferCreateInfo framebufferInfo = {};
        framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebufferInfo.renderPass = mRenderPass;
        framebufferInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
        framebufferInfo.pAttachments = attachments.data();
        framebufferInfo.width = swapChainExtent.width;
        framebufferInfo.height = swapChainExtent.height;
        framebufferInfo.layers = 1;

        if (vkCreateFramebuffer(mLogicalDevice.GetDevice(), &framebufferInfo, nullptr, &mSwapChainFramebuffers[i]) != VK_SUCCESS) 
        {
            throw std::runtime_error("failed to create framebuffer!");
        }
    }
}

void SwapChain::CreateSyncObjects() 
{
    mImageAvailableSemaphores.resize(FRAMES_IN_FLIGHT);
    mRenderFinishedSemaphores.resize(FRAMES_IN_FLIGHT);
    mInFlightFences.resize(FRAMES_IN_FLIGHT);
    mImagesInFlight.resize(GetImageCount(), VK_NULL_HANDLE);

    VkSemaphoreCreateInfo semaphoreInfo = {};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo = {};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    for (size_t i = 0; i < FRAMES_IN_FLIGHT; i++) {
    if (vkCreateSemaphore(mLogicalDevice.GetDevice(), &semaphoreInfo, nullptr, &mImageAvailableSemaphores[i]) !=
            VK_SUCCESS ||
        vkCreateSemaphore(mLogicalDevice.GetDevice(), &semaphoreInfo, nullptr,  &mRenderFinishedSemaphores[i]) !=
            VK_SUCCESS ||
        vkCreateFence(mLogicalDevice.GetDevice(), &fenceInfo, nullptr, &mInFlightFences[i]) != VK_SUCCESS) 
    {
        throw std::runtime_error("failed to create synchronization objects for a frame!");
    }
    }
}

VkFormat SwapChain::FindDepthFormat() 
{
  return mLogicalDevice.FindSupportedFormat(
      {VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT},
      VK_IMAGE_TILING_OPTIMAL,
      VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT);
}

VkResult SwapChain::AcquireNextImage(uint32_t *imageIndex) 
{
    vkWaitForFences(mLogicalDevice.GetDevice(), 1, &mInFlightFences[mCurrentFrame], VK_TRUE, 
                    std::numeric_limits<uint64_t>::max());

    VkResult result = vkAcquireNextImageKHR(
        mLogicalDevice.GetDevice(),
        mSwapChain,
        std::numeric_limits<uint64_t>::max(),
        mImageAvailableSemaphores[mCurrentFrame],  // must be a not signaled semaphore
        VK_NULL_HANDLE,
        imageIndex
    ); 

    return result;
}

VkResult SwapChain::SubmitCommandBuffers(const VkCommandBuffer *buffers, uint32_t *imageIndex) 
{
    if (mImagesInFlight[*imageIndex] != VK_NULL_HANDLE) 
    {
        vkWaitForFences(mLogicalDevice.GetDevice(), 1, &mImagesInFlight[*imageIndex], VK_TRUE, UINT64_MAX);
    }

    mImagesInFlight[*imageIndex] = mInFlightFences[mCurrentFrame];

    VkSubmitInfo submitInfo = {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore waitSemaphores[] = {mImageAvailableSemaphores[mCurrentFrame]};
    VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = buffers;

    VkSemaphore signalSemaphores[] = {mRenderFinishedSemaphores[mCurrentFrame]};
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    vkResetFences(mLogicalDevice.GetDevice(), 1, &mInFlightFences[mCurrentFrame]);
    if (vkQueueSubmit(mLogicalDevice.GetGraphicsQueue(), 1, &submitInfo, mInFlightFences[mCurrentFrame]) !=
        VK_SUCCESS) 
    {
        throw std::runtime_error("failed to submit draw command buffer!");
    }

    VkPresentInfoKHR presentInfo = {};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;

    VkSwapchainKHR swapChains[] = {mSwapChain};
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapChains;
    presentInfo.pImageIndices = imageIndex;

    auto result = vkQueuePresentKHR(mLogicalDevice.GetPresentQueue(), &presentInfo);

    mCurrentFrame = (mCurrentFrame + 1) % FRAMES_IN_FLIGHT;

    return result;
}


// Helper Functions.
//----------------------------------------------------------------
VkSurfaceFormatKHR SwapChain::ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats) 
{
    for (const auto &availableFormat : availableFormats) 
    {
        if (availableFormat.format == VK_FORMAT_B8G8R8A8_SRGB &&
            availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) 
        {
            return availableFormat;
        }
    }

    return availableFormats[0];
}

VkPresentModeKHR SwapChain::ChooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes) 
{
    for (const auto &availablePresentMode : availablePresentModes) 
    {
        if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) {
            std::cout << "Present mode: Mailbox" << std::endl;
            return availablePresentMode;
        }
    }

    // for (const auto &availablePresentMode : availablePresentModes) {
    //   if (availablePresentMode == VK_PRESENT_MODE_IMMEDIATE_KHR) {
    //     std::cout << "Present mode: Immediate" << std::endl;
    //     return availablePresentMode;
    //   }
    // }

    std::cout << "Present mode: V-Sync" << std::endl;
    return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D SwapChain::ChooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities) 
{
    if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) 
    {
        return capabilities.currentExtent;
    } 
    else {
        VkExtent2D actualExtent = mWindowExtent;
        actualExtent.width = std::max(
            capabilities.minImageExtent.width,
            std::min(capabilities.maxImageExtent.width, actualExtent.width));
        actualExtent.height = std::max(
            capabilities.minImageExtent.height,
            std::min(capabilities.maxImageExtent.height, actualExtent.height));

        return actualExtent;
    }
}

//----------------------------------------------------------------
}