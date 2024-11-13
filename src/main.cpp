#include "Game.h"

int main() {
    Game game;
    if (game.initialize()) {
        game.run();
    }
    game.shutdown();
    return 0;
}
