//
// Created by Danny Yeap on 11/6/19.
//

#include "Player.h"
#include <sstream>
#include <string>
#include <iostream>

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

Card Player::getCardPlayed() const {
    // Need to process Move to get card
    return cardPlayed;
}

bool Player::unoCalled() const {
    return uno;
}

Move Player::getMove() const {
    return move;
}

void Player::processMoveString() {
    //reset vectorMove
    vectorMove = {};
    std::string stringMove = this->getMove().getName();
    std::stringstream ssMove(stringMove);
    std::string tempStringMove;
    do{
        tempStringMove = "";
        ssMove >> tempStringMove;
        if(!tempStringMove.empty()){
            vectorMove.push_back(tempStringMove);
        }
    }while(!tempStringMove.empty());
}

std::string Player::getAction() const {
    return vectorMove.at(0);
}

void Player::drawInitialCard(Deck &deck) {
    this->addCardToHand(deck.draw());
}

void Player::processPlayMove() {
    // go through move string and store the card the player played and uno
    std::string color = vectorMove.at(1);
    int value = std::stoi(vectorMove.at(2)) ; // Need to double check
    cardPlayed = Card(color,value);
    if (vectorMove.back() == "uno") {
        uno = true;
    }
    else {
        uno = false;
    }
}

int Player::getNumCardsDrawnOnThisTurn() const {
    return numCardsDrawnOnThisTurn;
}

Card Player::getLastCardDrawn() const {
    return hand.back();
}

bool Player::drawCard(Deck& deck,const int &drawLimit) {
    bool successfullyDrewCard = true; // assume can draw the card
    if(drawLimit == numCardsDrawnOnThisTurn){
        successfullyDrewCard = false;
        return successfullyDrewCard;
    }
    else{
        this->addCardToHand(deck.draw());
        numCardsDrawnOnThisTurn++;
        return successfullyDrewCard;
    }
}

bool Player::getEndTurn() const {
    return endTurn;
}

std::vector<std::string> Player::getVectorMove() const {
    return vectorMove;
}
/*
void Player::endTurn() {
    numCardsDrawnOnThisTurn = 0;
    move = ;
    vectorMove = ;
    cardPlayed;
}
*/


