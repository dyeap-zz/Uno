//
// Created by Danny Yeap on 11/7/19.
//

#include "File.h"
#include <iostream>
#include <fstream>
#include <string>

File::File(const std::string& name):name(name){
    //read in file and store it into contents
    std::string currStr;
    std::ifstream someFile("../" + name);
    while (std::getline(someFile, currStr)){
        contents.push_back(currStr);
    }
}

std::vector<std::string> File::getContents() const {
    return contents;
}

