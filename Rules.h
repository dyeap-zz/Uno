//
// Created by Danny Yeap on 11/6/19.
//

#ifndef UNO_RULES_H
#define UNO_RULES_H
#include <string>
#include "File.h"
class Rules{
public:
    Rules(const std::string& name);
    int getStartingHandSize()const;
    std::string getReneging()const;
    int getDrawLimit()const;
    bool getMustPlayCardEachTurn()const;
    int getBadUnoCalloutPenalty()const;
    int getUnoCalloutPenalty()const;
private:
    int StartingHandSize;
    int UnoCalloutPenalty;
    int BadUnoCalloutPenalty;
    int DrawLimit;
    bool MustPlayCardEachTurn;
    std::string Reneging;
    File file;
};
#endif //UNO_RULES_H
