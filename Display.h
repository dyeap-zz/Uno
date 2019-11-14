#ifndef UNO_DISPLAY_H
#define UNO_DISPLAY_H
#include <iostream>
#include "Player.h"
#include "DiscardPile.h"
class Game;
class Display{
public:
    Display();
    //void getPlayerInfo();
    int getNumPlayers()const;
    std::string getPlayerName(int* playerNum)const;
    void showOtherPlayersHands(const std::vector<Player>& players,const Player* currPlayerTurn)const;
    void showCurrPlayerHand(const Player &player) const;
    void showDiscardPile(const DiscardPile &discardPile);
    void showYourHand(const Player& player)const;
    void getMove(Player& player) const;
    void showUnknownCommand()const;
    void showCardNotInHand(const Card& card)const;
    void showCannotPutInDiscard(const Card& card)const;
    void showReneging(const std::string& move)const;
    void showplayCard(Game game) const;
    void showCard(const Card& card) const;
    void showMaxCardDrawn()const;
    void showDiscardPileEmpty()const;
    void showCannotSkip(const int& numCardToDraw)const;
    void showHelp()const;
    void showQuit(const std::vector<Player> players) const;
    void showCannotCallUno()const;
    void showUnoPlayerNotValid(const std::string& name)const;
    void showUnoPlayerMoreThanOneCard(const Player& player)const;
    void showUnPlayeCalledUno(const Player& player)const;
    void showUnoCalledSuccessful(const Player& player)const;
private:

};
#endif //UNO_DISPLAY_H
