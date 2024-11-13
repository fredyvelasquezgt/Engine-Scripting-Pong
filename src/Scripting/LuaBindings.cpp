#include "LuaBindings.h"
#include "../Paddle.h"
#include "../Ball.h"

void LuaBindings::bind(sol::state& lua, entt::registry& registry) {
    lua.new_usertype<Paddle>("Paddle",
        "rect", &Paddle::rect,
        "speed", &Paddle::speed
    );

    lua.new_usertype<Ball>("Ball",
        "rect", &Ball::rect,
        "speedX", &Ball::speedX,
        "speedY", &Ball::speedY
    );

    lua["create_ball"] = [&](int x, int y, int w, int h, int speedX, int speedY) {
        auto entity = registry.create();
        registry.emplace<Ball>(entity, SDL_Rect{x, y, w, h}, speedX, speedY);
    };
}
