//
// Created by Danny Yeap on 11/6/19.
//

#ifndef UNO_CARD_H
#define UNO_CARD_H
#include <string>
class Card{
public:
    Card(std::string color,int value);
    Card();
    std::string getColor() const;
    int getValue() const;
    bool operator ==(const Card& rhs) const; // do the operator overload to see if the cards are the same
private:
    std::string color;
    int value;
};
#endif //UNO_CARD_H
