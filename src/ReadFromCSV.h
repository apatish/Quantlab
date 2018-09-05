#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "InputData.h"

class ReadFromCSV: public InputData
{
public:
    ReadFromCSV() = delete;
    ReadFromCSV(std::shared_ptr<std::vector<std::string>> argsArr);
    virtual ~ReadFromCSV();
    bool getRecord(std::shared_ptr<std::string> line);
private:
    std::ifstream in;
};

ReadFromCSV::ReadFromCSV(std::shared_ptr<std::vector<std::string>> argsArr) : InputData(argsArr),
in(argsArr->at(0), std::ios::binary)
{
    if (!in.is_open())
    {
        std::cerr << "Failed to open file name: " << argsArr->at(0).c_str() << std::endl;
    }
}
ReadFromCSV::~ReadFromCSV()
{
    in.close();
}
bool ReadFromCSV::getRecord(std::shared_ptr<std::string> line)
{
    if (std::getline(in, *line))
        return true;
    return false;
}