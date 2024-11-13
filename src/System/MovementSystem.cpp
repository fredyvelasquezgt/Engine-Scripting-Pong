#include "MovementSystem.h"
#include "../Paddle.h"
#include "../Ball.h"

void MovementSystem::init(entt::registry& reg) {
    registry = &reg;
}

void MovementSystem::update() {
    auto ballView = registry->view<Ball>();
    for (auto entity : ballView) {
        auto& ball = ballView.get<Ball>(entity);

        // Actualiza la posición de la pelota
        ball.rect.x += ball.speedX;
        ball.rect.y += ball.speedY;

        // Rebote de la pelota en la pared
        if (ball.rect.y <= 0 || ball.rect.y + ball.rect.h >= 600) {
            ball.speedY = -ball.speedY;
        }
    }
}
