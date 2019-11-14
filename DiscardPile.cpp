

#include "DiscardPile.h"

Card DiscardPile::getTopCard() const{
    if(cards.empty()){
        return phantomCard;
    }
    return cards.back();
}

void DiscardPile::add(Card card) {
    if (ptrPhantomCard){
        ptrPhantomCard = nullptr;
        phantomCard = {};
    }
    cards.push_back(card);
}

std::vector<Card> DiscardPile::getPileToShuffle() {
    phantomCard = cards.back();
    ptrPhantomCard = &phantomCard;
    std::vector<Card> discardPile = cards;
    cards = {};
    return discardPile;

}

bool DiscardPile::empty() const {
    return cards.empty();
}

