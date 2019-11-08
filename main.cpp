#include <iostream>
#include "CommandLineArgument.h"
#include "Game.h"
int main(int argc, char** argv) {
    CommandLineArgument cla(argc,argv);
    Game game(cla);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}