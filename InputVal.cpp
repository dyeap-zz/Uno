#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include "InputVal.h"

// std::string getValidString(const std::string& prompt)
void getInput(const std::string& prompt,std::string* playerName){
    bool read_successful = false;
    std::string input;
    std::string temp_s;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::stringstream ss_input(input);
        // Extracts everything until white spaces or \n reached
        ss_input >> *playerName;
        read_successful = checkForWhiteSpace(ss_input);
    }while(!read_successful);
}

void getInput(const std::string& prompt,int *num){
    bool read_successful = false;
    std::string input;
    std::string temp_s;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::stringstream ss_input(input);
        // Extracts everything until white spaces or \n reached
        ss_input >> *num;
        read_successful = checkForWhiteSpace(ss_input);
    }while(!read_successful);
}

bool checkForWhiteSpace(std::istream& input){
    char c = '!';
    // Check to see if the first >> got a valid num. If not return false
    if (input.fail()){
        return false;
    }
        // Check to see if there are no more characters to read
    else{
        input >> c;
        return input.fail();
    }
}