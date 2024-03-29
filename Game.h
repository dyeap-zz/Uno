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
    bool cardNotInHand(Player& player);
    bool cannotPutOnTopOfDiscardPile()const;
    bool mustPlayLastCardDrawn(const Player& player)const;
    void processDraw();
    void processSkip();
    bool cannotPlayAnyCards(const Player& player)const;
    void processQuit();
    void processUno();
    bool isInGame(const std::string& unoName)const;
    bool unoPlayerHasMorethanOneCard(const Player& player)const;
    bool unoPlayerCalledUno(const Player& player);
    Player* getUnoPlayer(const std::string& unoName);
    bool validMove(const Player& move)const;
    bool validPlayInput()const;
    Player getCurrPlayer()const;
    DiscardPile getDiscard()const;
    Rules getRules()const;
    Deck* getDeck();
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
    int currPlayerIndex;
    std::vector<std::string> validMoves = {"play","draw","skip","help","quit","uno"};
    //Player winner;

};
#endif //UNO_GAME_H
