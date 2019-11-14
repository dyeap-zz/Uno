//
// Created by Danny Yeap on 11/6/19.
//

#include "Player.h"
#include <sstream>
#include <string>
#include <iostream>
#include "Game.h"
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
    Card cardDrawn = deck.draw();
    score += cardDrawn.getValue();
    this->addCardToHand(cardDrawn);
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

bool Player::drawCard(Game& game) {
    bool successfullyDrewCard = true; // assume can draw the card
    int drawLimit = game.getRules().getDrawLimit();
    Deck* deck = game.getDeck();
    if(drawLimit == numCardsDrawnOnThisTurn){
        successfullyDrewCard = false;
        return successfullyDrewCard;
    }
    else{
        this->addCardToHand(deck->draw());
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

void Player::setCardPlayedIndex(const int &index) {
    cardPlayedIndex = index;
}

Card Player::getCardPlayedFromHand() const {
    return hand.at(cardPlayedIndex);
}

void Player::playCard(Game &game) {
    Card cardPlayed = this->getCardPlayedFromHand();
    game.getDiscard().add(cardPlayed);
    hand.erase(hand.begin()+cardPlayedIndex);
    endTurn = true;
}


void Player::turnEnding() {
    move = Move();
    vectorMove = {{}};
    cardPlayed = Card();
    cardPlayedIndex = -1;
}

bool Player::operator==(const Player &otherPlayer) {
    return this->getName() == otherPlayer.getName();

}

void Player::setEndTurn(const bool& end) {
    computeScore();
    this->endTurn = end;
}

void Player::completelyEndTurn() {
    numCardsDrawnOnThisTurn = 0;
    endTurn = false;
    this->turnEnding();
}

void Player::computeScore() {
    std::vector<Card>::iterator it;
    score = 0;
    for(it = hand.begin();it<hand.end();it++){
        score += (*it).getValue();
    }
}

int Player::getScore() const {
    return score;
}

void Player::setUno(const bool &unoVal) {
    uno = unoVal;
}

bool Player::getUno() const {
    return uno;
}

void Player::drawPenaltyCard(Deck& deck) {
    this->addCardToHand(deck.draw());
}




