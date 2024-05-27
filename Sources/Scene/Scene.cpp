#include "Scene.hpp"
#include "Physics/Physics.hpp"
#include "Physics/Collision.hpp"
#include "Logging.hpp"

namespace Super 
{

std::shared_ptr<OrthographicCamera> Scene::mCamera = nullptr;

     
Scene::Scene(EventBus& eventBus, uint32_t width, uint32_t height) 
{
    mCamera = std::make_shared<OrthographicCamera>(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

    // Player Entity.
    //
    Entity player = Entity{};
    player.flags = EntityFlags::ACTIVE | EntityFlags::IS_RIGID | EntityFlags::PLAYER_CONTROLLED;
    player.tx = {glm::vec2(150, 100), glm::vec2(50, 50)};
    player.body.inverseMass = 0.1f;
    player.body.force = {0.0f, 0.0f};
    player.body.velocity = {0.0f, 0.0f};
    player.body.staticFrictionCoefficient = 0.1f;
    player.body.dynamicFrictionCoefficient = 0.3f;
    player.body.restitution = 0.0f;
    player.color = glm::vec3(0.3f, 0.3f, 1.0f);
    player.label = "Player";
    mEntityManager.CreateEntity(std::move(player));

    // Box1 Entity.
    //
    Entity box1 = Entity{};
    box1.flags = EntityFlags::ACTIVE | EntityFlags::IS_RIGID;
    box1.tx = {glm::vec2(350, 100), glm::vec2(30, 30)};
    box1.body.inverseMass = 0.1f;
    box1.body.force = {0.0f, 0.0f};
    box1.body.velocity = {0.0f, 0.0f};
    box1.body.staticFrictionCoefficient = 0.1f;
    box1.body.dynamicFrictionCoefficient = 0.3f;
    box1.body.restitution = 0.0f;
    box1.color = glm::vec3(1.0f, 0.3f, 0.3f);
    box1.label = "Box1";
    mEntityManager.CreateEntity(std::move(box1));

    // Box2 Entity.
    //
    Entity box2 = Entity{};
    box2.flags = EntityFlags::ACTIVE | EntityFlags::IS_RIGID;
    box2.tx = {glm::vec2(350, 160), glm::vec2(30, 30)};
    box2.body.inverseMass = 0.1f;
    box2.body.force = {0.0f, 0.0f};
    box2.body.velocity = {0.0f, 0.0f};
    box2.body.staticFrictionCoefficient = 0.1f;
    box2.body.dynamicFrictionCoefficient = 0.3f;
    box2.body.restitution = 0.0f;
    box2.color = glm::vec3(1.0f, 0.3f, 0.3f);
    box2.label = "Box2";
    mEntityManager.CreateEntity(std::move(box2));

    // Box3 Entity.
    //
    Entity box3 = Entity{};
    box3.flags = EntityFlags::ACTIVE | EntityFlags::IS_RIGID;
    box3.tx = {glm::vec2(350, 220), glm::vec2(30, 30)};
    box3.body.inverseMass = 0.1f;
    box3.body.force = {0.0f, 0.0f};
    box3.body.velocity = {0.0f, 0.0f};
    box3.body.staticFrictionCoefficient = 0.1f;
    box3.body.dynamicFrictionCoefficient = 0.3f;
    box3.body.restitution = 0.0f;
    box3.color = glm::vec3(1.0f, 0.3f, 0.3f);
    box3.label = "Box3";
    mEntityManager.CreateEntity(std::move(box3));

    // Box4 Entity.
    //
    Entity box4 = Entity{};
    box4.flags = EntityFlags::ACTIVE | EntityFlags::IS_RIGID;
    box4.tx = {glm::vec2(350, 280), glm::vec2(30, 30)};
    box4.body.inverseMass = 0.1f;
    box4.body.force = {0.0f, 0.0f};
    box4.body.velocity = {0.0f, 0.0f};
    box4.body.staticFrictionCoefficient = 0.1f;
    box4.body.dynamicFrictionCoefficient = 0.3f;
    box4.body.restitution = 0.0f;
    box4.color = glm::vec3(1.0f, 0.3f, 0.3f);
    box4.label = "Box4";
    mEntityManager.CreateEntity(std::move(box4));

    // Platform 1 Entity.
    //
    Entity platform1 = Entity{};
    platform1.flags = EntityFlags::ACTIVE | EntityFlags::IS_RIGID;
    platform1.tx = {glm::vec2(300, 400), glm::vec2(200, 20)};
    platform1.body.inverseMass = 0.0f;
    platform1.body.force = {0.0f, 0.0f};
    platform1.body.velocity = {0.0f, 0.0f};
    platform1.body.staticFrictionCoefficient = 0.1f;
    platform1.body.dynamicFrictionCoefficient = 0.3f;
    platform1.body.restitution = 0.0f;
    platform1.color = glm::vec3(0.5f, 0.2f, 0.8f);
    platform1.label = "Platform1";
    mEntityManager.CreateEntity(std::move(platform1));

    // Platform 2 Entity.
    //
    Entity platform2 = Entity{};
    platform2.flags = EntityFlags::ACTIVE | EntityFlags::IS_RIGID;
    platform2.tx = {glm::vec2(100, 300), glm::vec2(200, 20)};
    platform2.body.inverseMass = 0.0f;
    platform2.body.force = {0.0f, 0.0f};
    platform2.body.velocity = {0.0f, 0.0f};
    platform2.body.staticFrictionCoefficient = 0.1f;
    platform2.body.dynamicFrictionCoefficient = 0.3f;
    platform2.body.restitution = 0.0f;
    platform2.color = glm::vec3(0.5f, 0.2f, 0.8f);
    platform2.label = "Platform2";
    mEntityManager.CreateEntity(std::move(platform2));

    // Platform 3 Entity.
    //
    Entity platform3 = Entity{};
    platform3.flags = EntityFlags::ACTIVE | EntityFlags::IS_RIGID;
    platform3.tx = {glm::vec2(500, 300), glm::vec2(200, 20)};
    platform3.body.inverseMass = 0.0f;
    platform3.body.force = {0.0f, 0.0f};
    platform3.body.velocity = {0.0f, 0.0f};
    platform3.body.staticFrictionCoefficient = 0.1f;
    platform3.body.dynamicFrictionCoefficient = 0.3f;
    platform3.body.restitution = 0.0f;
    platform3.color = glm::vec3(0.5f, 0.2f, 0.8f);
    platform3.label = "Platform3";
    mEntityManager.CreateEntity(std::move(platform3));

    // Background Entity.
    //
    Entity background = Entity{};
    background.flags = EntityFlags::ACTIVE;
    background.tx = {glm::vec2(0, 0), glm::vec2(800, 600)};
    background.body.inverseMass = 0.0f;
    background.body.force = {0.0f, 0.0f};
    background.body.velocity = {0.0f, 0.0f};
    background.body.staticFrictionCoefficient = 0.1f;
    background.body.dynamicFrictionCoefficient = 0.3f;
    background.body.restitution = 0.0f;
    background.color = glm::vec3(0.3f, 0.3f, 1.0f);
    background.label = "Background";
    mEntityManager.CreateEntity(std::move(background));

    // Event-Specific callback classes.
    // These classes don't have any functions that are called each frame, but rather
    // provide callbacks for the EventBus, so they just exist and remain idle for the 
    // entire application (until the program closes).
    //
    mPlayerController = std::make_unique<PlayerController>(eventBus, mEntityManager.GetAllEntities()[0]);




    // ECS Systems.
    // Unlike event callbacks, these systems are run each frame and have more of a profound
    // impact on the application, though they may still publish and subscribe to events.
    //   
    mSystems.emplace_back(std::move(std::make_unique<Physics>(eventBus)));
    mSystems.emplace_back(std::move(std::make_unique<Collision>(eventBus, width, height)));
}

Scene::~Scene() 
{
    // Doesn't need to manually free any memory... empty for now.
}

void Scene::Update() 
{
    for(const auto& sys : mSystems) 
    {
        sys->Update(mEntityManager.GetAllEntities());
    }
}


}