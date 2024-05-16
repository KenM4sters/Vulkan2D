#include "RenderSystem.hpp"
#include "../Entity.hpp"

namespace Super 
{
class PlayerSystem : public RenderSystem 
{
public:
    PlayerSystem(const std::shared_ptr<Device>& device, VkRenderPass renderPass, uint32_t height, uint32_t width);

    ~PlayerSystem() {}

    void CreatePlayerEntity();

    void CreatePipelineLayout() override;

    void CreatePipeline(uint32_t width, uint32_t height, VkRenderPass renderPass) override;
    
    void UpdateBuffers() override;

    void Run(VkCommandBuffer commandBuffer) override;
};
}