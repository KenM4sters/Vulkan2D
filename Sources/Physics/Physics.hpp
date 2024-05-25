#pragma once
#include "Scene/System.hpp"

#define G -0.09

namespace Super
{
class Physics : public System 
{
public:
    Physics(EventBus& eventBus) : System(eventBus) {}
    ~Physics() {}

    virtual void Update(std::vector<Entity>& entities) override;

private:
    void UpdateMotion(Entity& entity);
    
    void ResetMotion(Entity& entity);

    void SolveImpulse(CollisionEvent* event);

};
}