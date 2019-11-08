//
// Created by Danny Yeap on 11/6/19.
//

#ifndef UNO_PLAYER_H
#define UNO_PLAYER_H
#include <string>
#include "Card.h"
#include "Move.h"
#include <vector>
class Player{
public:
    Player(const std::string& name);
    void addCardToHand(Card card);
    //void setName(const std::string& name);
private:
    std::string name;
    std::vector<Card> hand;
    Move move;
};
#endif //UNO_PLAYER_H
