#ifndef UNO_DISPLAY_H
#define UNO_DISPLAY_H
#include <iostream>
#include "Player.h"
#include "DiscardPile.h"
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
private:

};
#endif //UNO_DISPLAY_H
