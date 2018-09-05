#pragma once
#include <memory>

//Can be expanded to different types of input(such as real time data)
class InputData
{
public:
    InputData() = delete;
    InputData(std::shared_ptr<std::vector<std::string>> argsArr) {};
    virtual ~InputData() {};
    virtual bool getRecord(std::shared_ptr<std::string> line) = 0;
private:
    
    
};
