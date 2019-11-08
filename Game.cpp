#include "CommandLineArgument.h"
#include "Game.h"
#include "Deck.h"
#include "Random.h"

Game::Game(CommandLineArgument cla):deck(cla.getDeckFileName()), rules(cla.getRulesFileName()), random(cla.getSeed()) {

}



