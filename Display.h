#ifndef UNO_DISPLAY_H
#define UNO_DISPLAY_H
#include <iostream>
class Display{
public:
    Display();
    //void getPlayerInfo();
    int getNumPlayers()const;
    std::string getPlayerName(int* playerNum)const;
private:

};
#endif //UNO_DISPLAY_H
