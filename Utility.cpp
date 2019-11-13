
#include "Utility.h"
#include <string>
bool isSubStr(const std::string &leftStr, const std::string &rightStr) {
    int position = 0;
    int smallestStrSize = std::min(leftStr.size(),rightStr.size());
    if (smallestStrSize == 0){
        return false;
    }
    while(position < smallestStrSize){
        if(std::tolower(leftStr[position]) != std::tolower(rightStr[position])){
            return false;
        }
        position++;
    }
    return true;
}

bool isInteger(const std::string &str) {
    std::string::const_iterator it = str.begin();
    while(it!=str.end() && std::isdigit(*it)){
        it++;
    }
    // if reach end then all number
    return it==str.end() && !str.empty();
}

