#pragma once
#include <SDL2/SDL.h>
#include <entt/entt.hpp>
#include <sol/sol.hpp>
#include "System/RenderSystem.h"
#include "System/MovementSystem.h"

class Game {
public:
    Game();
    bool initialize();
    void run();
    void shutdown();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    entt::registry registry;
    RenderSystem renderSystem;
    MovementSystem movementSystem;
    sol::state lua;
};
