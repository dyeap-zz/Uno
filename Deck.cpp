#include "Deck.h"
#include "Card.h"
#include "Random.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include "DiscardPile.h"

Deck::Deck(std::string name):file(name){
    // read contents of file
    std::vector<std::string> fileContents = file.getContents();
    std::string v = "10";
    std::string a = v.substr(0,1);
    for (int row = 0;row<static_cast<int>(fileContents.size());row++){
        std::string currStr = fileContents[row];
        std::stringstream ss(currStr);
        int numCards;
        ss >> numCards;
        std::string color;
        ss >> color;
        int value;
        ss >> value;
        //int numCards = static_cast<int>(currStr.at(0))-'0';
        //int value = static_cast<int>(currStr.at(currStr.size()-1)) - '0';
        //currStr.erase(0,2);
        //currStr.erase(currStr.size()-1,2);
        //std::string color = currStr;
        for (int i = 0; i < numCards; ++i) {
            cards.push_back(Card(color,value));
        }
    }
}
/*
Card Deck::getCard(Random& random) {
    int position = random.getNum(0,getSize()-1);
    // create card and erase from deck
    Card CardDrawn(cards[position].getColor(),cards[position].getValue());
    cards.erase(cards.begin()+position);
    return CardDrawn;
}
*/
int Deck::getSize() const{
    return cards.size();
}

void Deck::shuffle() {
    std::shuffle(cards.begin(),cards.end(),std::default_random_engine(0));

}

Card Deck::draw() {
    //Card cardDrawn(cards.pop_back());
    Card cardDrawn = cards.back();
    cards.pop_back();
    return cardDrawn;
}

bool Deck::isEmpty() const {
    return this->getSize() <= 0;
}

bool Deck::moveDiscardToDeck(DiscardPile& discard) { //deck is guaranteed empty
    if(!discard.empty()){
        cards = discard.getPileToShuffle();
        return true;
    }
    return false;
}
