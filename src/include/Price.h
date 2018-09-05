#pragma once
#include <memory>

class Price
{
public:
    Price();
    ~Price();
    bool parseValue(const std::string & value);
    std::shared_ptr<int> getValue();
private:
    std::shared_ptr<int> _price;
};

Price::Price()
{}

Price::~Price()
{}

bool Price::parseValue(const std::string & value)
{
    _price = std::make_shared<int>(std::stoi(value.c_str()));
    if (*_price > 0)
        return true;
    std::cerr << "ERROR!!! Price: " << value << std::endl;
    return false;
}

std::shared_ptr<int> Price::getValue()
{
    return _price;
}