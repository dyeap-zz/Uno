//
// Created by Danny Yeap on 11/6/19.
//

#ifndef UNO_PLAYER_H
#define UNO_PLAYER_H
#include <string>
#include "Card.h"
#include "Move.h"
class Player{
public:
    Player(const std::string& name);
private:
    std::string name;
    std::vector<Card> Hand;
    Move move;
};
#endif //UNO_PLAYER_H
