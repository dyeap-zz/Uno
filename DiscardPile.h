#ifndef UNO_DISCARDPILE_H
#define UNO_DISCARDPILE_H
#include <vector>
#include "Card.h"
class DiscardPile{
public:
    Card getTopCard()const;
    void add(Card card);
    std::vector<Card> getPileToShuffle();
    void removePhantomCard();
    bool empty()const;

private:
    std::vector<Card> cards;
    Card phantomCard;
    Card* ptrPhantomCard;
};
#endif //UNO_DISCARDPILE_H
