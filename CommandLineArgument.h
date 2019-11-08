#ifndef UNO_COMMANDLINEARGUMENT_H
#define UNO_COMMANDLINEARGUMENT_H
#include <iostream>
#include <string>
class CommandLineArgument{
public:
    CommandLineArgument (int argc,char** agrv);
    std::string getDeckFileName();
    std::string getRulesFileName();
    int getSeed();
private:
    std::string deckFileName = "Regular.txt";
    std::string rulesFileName = "Default.txt";
    int seed = 2;
};
#endif //UNO_COMMANDLINEARGUMENT_H
