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
    void shuffleDeck();
    void dealInitialHand();
    void flipOneCardToDiscard();
    void chooseStartingPlayer();
    void startGame();
    void processMove();
    void processPlay();
    bool cardNotInHand(const Player& player);
    bool cannotPutOnTopOfDiscardPile()const;
    bool mustPlayLastCardDrawn(const Player& player)const;
    void processDraw();
    void processSkip();
    bool cannotPlayAnyCards(const Player& player)const;

    bool validMove(const Player& move)const;
    bool validPlayInput()const;
private:
    Deck deck;
    Rules rules;
    Random random;
    Display display;
    std::vector<Player> players;
    int numPlayers;
    Player* winner = nullptr;
    DiscardPile discard;
    Player* currPlayerTurn;
    std::vector<std::string> validMoves = {"play","draw","skip","help","quit"};
    //Player winner;

};
#endif //UNO_GAME_H
