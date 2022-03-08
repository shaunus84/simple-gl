#include "Game.h"
//--- Main ---//

int main(int argc, char** argv) {
    simplegl::Game game;

    if (game.Initialise(640, 480)) {
        game.RunLoop();
    }

    game.Shutdown();

    return 0;
}

//-----------//