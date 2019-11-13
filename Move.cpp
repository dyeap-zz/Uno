#include "Move.h"
#include <vector>
#include <string>
//const static std::vector<std::string> validMoves = std::vector<std::string>({"play","draw","skip","help","quit"});
Move::Move() {
    //this->validMoves = std::vector<std::string>({"play","draw","skip","help","quit"});
}
Move::Move(std::string name) {
    this->name = name;
    //this->validMoves = std::vector<std::string>({"play","draw","skip","help","quit"});
}

void Move::setName(const std::string& name) {
     this->name = name;
}

std::string Move::getName() const {
    return name;
}
/*
std::vector<std::string> Move::getValidMoves() const {
    return validMoves;
}
*/
