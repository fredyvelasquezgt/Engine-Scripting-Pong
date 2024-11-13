#include "RenderSystem.h"

void RenderSystem::init(SDL_Renderer* rend, entt::registry& reg) {
    renderer = rend;
    registry = &reg;
}

void RenderSystem::update() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    auto view = registry->view<SDL_Rect>();  // Asumimos que cada paddle y pelota tiene SDL_Rect para su posición
    for (auto entity : view) {
        SDL_Rect& rect = view.get<SDL_Rect>(entity);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}
