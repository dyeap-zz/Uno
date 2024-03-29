#include "Card.h"
#include "Utility.h"
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

Card::Card() {

}

bool Card::operator==(const Card &rhs) const {
    std::string lhsColor = this->getColor();
    int lhsValue = this->getValue();
    std::string rhsColor = rhs.getColor();
    int rhsValue = rhs.getValue();
    return isSubStr(lhsColor,rhsColor) && lhsValue == rhsValue;

}


