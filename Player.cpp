//
// Created by Danny Yeap on 11/6/19.
//

#include "Player.h"

Player::Player(const std::string &name):name(name) {

}

void Player::addCardToHand(Card card) {
    hand.push_back(card);
}

std::string Player::getName()const {
    return name;
}

std::vector<Card> Player::getHand()const{
    return hand;
}

void Player::setMove(Move move) {
    this->move = move;
}

