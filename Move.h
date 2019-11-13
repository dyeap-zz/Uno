//
// Created by Danny Yeap on 11/6/19.
//

#ifndef UNO_MOVE_H
#define UNO_MOVE_H
#include <string>
#include <vector>
class Move{
public:
    Move();
    Move(std::string name);
    void setName(const std::string& name);
    std::string getName()const;
    //std::vector<std::string> getValidMoves()const;

private:
    std::string name;
    //static std::vector<std::string> validMoves;
};
//const static std::vector<std::string> validMoves = std::vector<std::string>({"play","draw","skip","help","quit"});

#endif //UNO_MOVE_H
