#include "Display.h"
#include <iostream>
#include "InputVal.h"
#include <string>
Display::Display() {

}

int Display::getNumPlayers() const {
    int numPlayers;
    std::string prompt = "Enter the number of players in the game: ";
    getInput(prompt, &numPlayers);
    return numPlayers;
}

std::string Display::getPlayerName(int* playerNum) const {
    std::string playerName;
    std::string prompt = "Player " + std::to_string(*playerNum) + " enter your name: ";
    getInput(prompt,&playerName);
    return playerName;
}


/*
void Display::getPlayerInfo() {
    int numPlayers;
    std::string playerName;
    std::string prompt = "Enter the number of players in the game: ";
    getInput(prompt, &numPlayers);
    for(int currPlayer = 0;currPlayer<numPlayers;currPlayer++){
        std::string prompt = ""
        getInput(prompt)
    }
    std::cout << numPlayers <<std::endl;

}
*/