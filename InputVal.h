#ifndef UNO_INPUTVAL_H
#define UNO_INPUTVAL_H
#include <string>
void getInput(const std::string& prompt, int *num);
void getInput(const std::string& prompt, std::string* playerName);
bool checkForWhiteSpace(std::istream& input);
#endif //UNO_INPUTVAL_H
