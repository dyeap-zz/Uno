//
// Created by Danny Yeap on 11/6/19.
//

#ifndef UNO_CARD_H
#define UNO_CARD_H
#include <string>
class Card{
public:
    Card(std::string color,int value);
    std::string getColor() const;
    int getValue() const;
private:
    std::string color;
    int value;
};
#endif //UNO_CARD_H
