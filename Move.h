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
private:
    std::string name;

};
#endif //UNO_MOVE_H
