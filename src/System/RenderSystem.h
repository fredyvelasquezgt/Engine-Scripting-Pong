#pragma once
#include <SDL2/SDL.h>
#include <entt/entt.hpp>

class RenderSystem {
public:
    void init(SDL_Renderer* renderer, entt::registry& registry);
    void update();
private:
    SDL_Renderer* renderer;
    entt::registry* registry;
};
