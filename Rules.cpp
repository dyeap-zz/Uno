//
// Created by Danny Yeap on 11/6/19.
//

#include "Rules.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
Rules::Rules(const std::string &name): file(name) {
    std::vector<std::string> fileContents = file.getContents();
    for (int row = 0; row < static_cast<int>(fileContents.size()) ; row++) {
        std::string currStr = fileContents[row];
        std::stringstream ss(currStr);
        std::string rule;
        char colon;
        ss >> rule;
        ss >> colon;
        if (rule == "StartingHandSize") {
            ss >> StartingHandSize;
        } else if (rule == "UnoCalloutPenalty") {
            ss >> UnoCalloutPenalty;
        } else if (rule == "BadUnoCalloutPenalty") {
            ss >> BadUnoCalloutPenalty;
        } else if (rule == "DrawLimit") {
            ss >> DrawLimit;
        } else if (rule == "MustPlayCardEachTurn") {
            ss >> MustPlayCardEachTurn;
        } else if (rule == "Reneging") {
            ss >> Reneging;
        } else {
            std::cout << "Rule doesn't exist." << std::endl;
        }
    }
}

int Rules::getStartingHandSize() const {
    return StartingHandSize;
}

std::string Rules::getReneging()const{
    return Reneging;
}

int Rules::getDrawLimit() const {
    return DrawLimit;
}

bool Rules::getMustPlayCardEachTurn() const {
    return MustPlayCardEachTurn;
}
