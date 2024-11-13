#include "Game.h"
#include "Scripting/LuaBindings.h"

Game::Game() : window(nullptr), renderer(nullptr) {}

bool Game::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;
    window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    lua.open_libraries(sol::lib::base);
    LuaBindings::bind(lua, registry);
    lua.script_file("scripts/config.lua");
    renderSystem.init(renderer, registry);
    movementSystem.init(registry);
    return true;
}

void Game::run() {
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }
        movementSystem.update();
        renderSystem.update();
        SDL_RenderPresent(renderer);
    }
}

void Game::shutdown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
