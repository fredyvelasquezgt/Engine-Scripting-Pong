#pragma once
#include <entt/entt.hpp>

class MovementSystem {
public:
    void init(entt::registry& registry);
    void update();
private:
    entt::registry* registry;
};
