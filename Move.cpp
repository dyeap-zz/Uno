#include "Move.h"

Move::Move() {

}
Move::Move(std::string name) {
    this->name = name;
}

void Move::setName(const std::string& name) {
     this->name = name;
}

