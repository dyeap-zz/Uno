#ifndef UNO_GAME_H
#define UNO_GAME_H
#include "Deck.h"
#include "CommandLineArgument.h"
#include "Rules.h"
#include "Random.h"
#include "Player.h"
#include "Display.h"
#include "DiscardPile.h"
class Game{
public:
    Game(CommandLineArgument cla);
    void play();
    void askForPlayerInfo();
    void dealInitialHand();
    void flipOneCardToDiscard();
    void chooseStartingPlayer();
private:
    Deck deck;
    Rules rules;
    Random random;
    Display display;
    std::vector<Player> players;
    int numPlayers;
    DiscardPile discard;
    Player* currPlayerTurn;
    //Player winner;

};
#endif //UNO_GAME_H
