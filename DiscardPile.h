#ifndef UNO_DISCARDPILE_H
#define UNO_DISCARDPILE_H
#include <vector>
#include "Card.h"
class DiscardPile{
public:
    Card getTopCard()const;
    void add(Card card);

private:
    std::vector<Card> cards;
};
#endif //UNO_DISCARDPILE_H
