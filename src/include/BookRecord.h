#pragma once
#include <cstring>
#include <iostream>
struct BookRecord
{
    int                                     MaxPrice;
    int                                     WeightedAveragePrice;
    unsigned long long int                  MaxTimeGap;
    unsigned long long int                  Volume;
    unsigned long long int                  PriceQuantity;
    std::shared_ptr<int>                    Quantity;
    std::shared_ptr<int>                    Price;
    std::shared_ptr<unsigned long long int> TimeStamp;
    std::shared_ptr<std::string>            Symbol;
    BookRecord():
        MaxTimeGap(0),
        Volume(0),
        MaxPrice(0),
        WeightedAveragePrice(0),
        PriceQuantity(0)
    {}
    std::string getLine()
    {
        //<symbol>,<MaxTimeGap>,<Volume>,<WeightedAveragePrice>,<MaxPrice>
        _line.assign(*Symbol + ',');
        _line.append(std::to_string(MaxTimeGap) + ',');
        _line.append(std::to_string(Volume) + ',');
        _line.append(std::to_string(WeightedAveragePrice) + ',');
        _line.append(std::to_string(MaxPrice) + '\n');
        return _line;
    }
private:
    std::string _line;
};