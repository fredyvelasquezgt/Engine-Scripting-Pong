#pragma once
#include <SDL2/SDL.h>
#include <entt/entt.hpp>

struct Ball {
    SDL_Rect rect;
    int speedX;
    int speedY;
};
