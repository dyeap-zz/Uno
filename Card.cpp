#include "Card.h"

Card::Card(std::string color, int value){
    this->color = color;
    this->value = value;
}

int Card::getValue() const {
    return value;
}

std::string Card::getColor() const{
    return color;
}


