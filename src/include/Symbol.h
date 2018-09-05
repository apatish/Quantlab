#pragma once
#include <memory>
#include <cctype>

class Symbol
{
public:
    Symbol();
    ~Symbol();
    bool parseValue(const std::string & value);
    std::shared_ptr<std::string> getValue();
private:
    std::shared_ptr<std::string> _symbol;
};

Symbol::Symbol()
{
}

Symbol::~Symbol()
{
}

bool Symbol::parseValue(const std::string & value)
{
    if (value.length() == 3)
    {
        _symbol = std::make_shared<std::string>(value);
        return true;
    }
    std::cerr << "ERROR!!! Symbol: " << value << std::endl;
    return false;
 }

std::shared_ptr<std::string> Symbol::getValue()
{
    return _symbol;
}