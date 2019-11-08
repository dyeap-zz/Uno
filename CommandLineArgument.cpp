

#include "CommandLineArgument.h"

CommandLineArgument::CommandLineArgument(int argc, char **argv) {
    // Process Later
}

std::string CommandLineArgument::getRulesFileName() {
    return rulesFileName;
}

std::string CommandLineArgument::getDeckFileName() {
    return deckFileName;
}

int CommandLineArgument::getSeed() {
    return seed;
}

