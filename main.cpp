#include "CommandLineArgument.h"
#include "Game.h"
int main(int argc, char** argv) {
    CommandLineArgument cla(argc,argv);
    Game game(cla);
    game.play();
    return 0;
}