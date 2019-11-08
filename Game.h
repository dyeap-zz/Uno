#ifndef UNO_GAME_H
#define UNO_GAME_H
#include "Deck.h"
#include "CommandLineArgument.h"
#include "Rules.h"
#include "Random.h"
class Game{
public:
    Game(CommandLineArgument cla);
    void play();

private:
    Deck deck;
    Rules rules;
    Random random;
};
#endif //UNO_GAME_H
