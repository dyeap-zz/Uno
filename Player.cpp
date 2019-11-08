//
// Created by Danny Yeap on 11/6/19.
//

#include "Player.h"

Player::Player(const std::string &name):name(name) {

}

void Player::addCardToHand(Card card) {
    hand.push_back(card);
}

