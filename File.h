#ifndef UNO_FILE_H
#define UNO_FILE_H
#include <string>
#include <vector>
class File{
public:
    File(const std::string& name);
    std::vector<std::string> getContents() const;
private:
    std::string name;
    std::vector<std::string> contents;
};
#endif //UNO_FILE_H
