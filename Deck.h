#ifndef UNO_DECK_H
#define UNO_DECK_H

#include <vector>
#include <iostream>
#include <string>
#include "File.h"
#include "Deck.h"
#include "Card.h"
#include "Random.h"
class Deck{
public:
    Deck(std::string name);
    Card getCard(Random& random);
    int getSize();
private:
    std::vector<Card> cards;
    File file;
};

#endif //UNO_DECK_H
