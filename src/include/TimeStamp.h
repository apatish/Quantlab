#pragma once
#include <memory>
#include <string>

class TimeStamp
{
public:
    TimeStamp();
    ~TimeStamp();
    bool parseValue(const std::string value);
    std::shared_ptr<unsigned long long int> getValue();
private:
    std::shared_ptr<unsigned long long int> _timeStamp;
};

TimeStamp::TimeStamp()
{}

TimeStamp::~TimeStamp()
{}

bool TimeStamp::parseValue(const std::string value)
{
    if (value.length() < 12)
    {
        _timeStamp = std::make_shared<unsigned long long int>(std::stoull(value.c_str()));
        if (_timeStamp >= 0)
            return true;
    }
    std::cerr << "ERROR!!! TimeStamp: " << value << std::endl;
    return false;
}

std::shared_ptr<unsigned long long int> TimeStamp::getValue()
{
    return _timeStamp;
}