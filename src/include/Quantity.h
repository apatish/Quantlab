#pragma once
#include <memory>

class Quantity
{
public:
    Quantity();
    ~Quantity();
    bool parseValue(const std::string & value);
    std::shared_ptr<int> getValue();
private:
    std::shared_ptr<int> _quantity;
};

Quantity::Quantity()
{
}

Quantity::~Quantity()
{
}

bool Quantity::parseValue(const std::string & value)
{
    _quantity = std::make_shared <int>(std::stoi(value.c_str()));
    if (*_quantity > 0)
        return true;
    std::cerr << "ERROR!!! Quantity: " << value << std::endl;
    return false;
}

std::shared_ptr<int> Quantity::getValue()
{
    return _quantity;
}