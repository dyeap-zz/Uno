

#include "DiscardPile.h"

Card DiscardPile::getTopCard() {
    return cards.back();
}

void DiscardPile::add(Card card) {
    cards.push_back(card);
}

