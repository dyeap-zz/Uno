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