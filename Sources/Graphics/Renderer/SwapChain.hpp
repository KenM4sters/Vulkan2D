#pragma once
#include <vulkan/vulkan.hpp>
#include "Graphics/Devices/LogicalDevice.hpp"

namespace mt 
{

struct SwapChainSupportDetails 
{
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices 
{
  uint32_t graphicsFamily;
  uint32_t presentFamily;
  bool graphicsFamilyHasValue = false;
  bool presentFamilyHasValue = false;
  bool isComplete() { return graphicsFamilyHasValue && presentFamilyHasValue; }
};

class SwapChain 
{
public:
    SwapChain(const PhysicalDevice& physicalDevice, const LogicalDevice& logicalDevice, VkExtent2D extent);
    SwapChain(const PhysicalDevice& physicalDevice, const LogicalDevice& logicalDevice, VkExtent2D extent, std::shared_ptr<SwapChain>& previous);
    ~SwapChain();

    SwapChain(const SwapChain& other) = delete;
    SwapChain& operator=(const SwapChain& other) = delete;

    static constexpr int FRAMES_IN_FLIGHT = 2;

    VkFormat FindDepthFormat();
    VkResult AcquireNextImage(uint32_t *imageIndex);
    VkResult SubmitCommandBuffers(const VkCommandBuffer *buffers, uint32_t *imageIndex);

    bool compareSwapFormats(const SwapChain& swapChain) const 
    {
        return swapChain.mSwapChainDepthFormat == mSwapChainDepthFormat &&
            swapChain.mSwapChainImageFormat == mSwapChainImageFormat;
    }

    float GetExtentAspectRatio() 
    {
        return static_cast<float>(mSwapChainExtent.width) / (mSwapChainExtent.height);
    }

    inline VkFramebuffer GetFrameBuffer(int index) const { return mSwapChainFramebuffers[index]; }
    inline VkRenderPass GetRenderPass() const { return mRenderPass; }
    inline VkImageView GetImageView(int index) const { return mSwapChainImageViews[index]; }
    inline size_t GetImageCount() const { return mSwapChainImages.size(); }
    inline VkFormat GetSwapChainImageFormat() const { return mSwapChainImageFormat; }
    inline VkExtent2D GetSwapChainExtent() const { return mSwapChainExtent; }
    inline uint32_t GetWidth() const { return mSwapChainExtent.width; }
    inline uint32_t GetHeight() const { return mSwapChainExtent.height; }

private:
    void Init();
    void CreateSwapChain();
    void CreateImageViews();
    void CreateDepthResources();
    void CreateRenderPass();
    void CreateFramebuffers();
    void CreateSyncObjects();

    VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
    VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
    VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

private:
    const PhysicalDevice& mPhysicalDevice;
    const LogicalDevice& mLogicalDevice;

    std::shared_ptr<SwapChain> mPreviousSwapChain = nullptr;
    VkExtent2D mWindowExtent;
    VkSwapchainKHR mSwapChain;

    VkFormat mSwapChainImageFormat;
    VkFormat mSwapChainDepthFormat;
    VkExtent2D mSwapChainExtent;
    VkRenderPass mRenderPass;

    std::vector<VkFramebuffer> mSwapChainFramebuffers;
    std::vector<VkImage> mDepthImages;
    std::vector<VkDeviceMemory> mDepthImageMemorys;
    std::vector<VkImageView> mDepthImageViews;
    std::vector<VkImage> mSwapChainImages;
    std::vector<VkImageView> mSwapChainImageViews;
    std::vector<VkSemaphore> mImageAvailableSemaphores;
    std::vector<VkSemaphore> mRenderFinishedSemaphores;
    std::vector<VkFence> mInFlightFences;
    std::vector<VkFence> mImagesInFlight;

    size_t mCurrentFrame = 0;

};
}