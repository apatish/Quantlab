#pragma once
#include <vector>
#include <memory>

class CommandLineArgs
{
public:
    CommandLineArgs() = delete;
    CommandLineArgs(int argCount, char ** argValues);
    ~CommandLineArgs();
    std::shared_ptr<std::vector<std::string>> getArgsArr();
private:
    std::shared_ptr<std::vector<std::string>> argsArr;
};

CommandLineArgs::CommandLineArgs(int argCount, char ** argValues)
{
    argsArr = std::make_shared<std::vector<std::string>>();
    for (int i = 1; i < argCount; ++i) // argv[0] is the path to the program
    { 
        argsArr->push_back(argValues[i]);
    }
}

CommandLineArgs::~CommandLineArgs()
{}

std::shared_ptr<std::vector<std::string>> CommandLineArgs::getArgsArr()
{
    return argsArr;
}