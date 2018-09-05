#pragma once
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <set>
#include <fstream>
#include "BookRecord.h"
#include "Symbol.h"
#include "TimeStamp.h"
#include "Quantity.h"
#include "Price.h"

class Book
{
public:
    Book() = delete;
    Book(std::string OutFileName);
    ~Book();
    void updateBook();
    void outputBook();
    bool findRecord();
    void addRecord();
    void registerValue(Symbol & smbl);
    void registerValue(TimeStamp & ts);
    void registerValue(Quantity & qty); 
    void registerValue(Price & price); 
private:
    std::shared_ptr<int>                    _quantity;
    std::shared_ptr<int>                    _price;
    std::shared_ptr<unsigned long long int> _timeStamp;
    std::shared_ptr<std::string>            _symbol;

    std::unordered_map<std::string, std::shared_ptr<BookRecord>>           _bookMap;
    std::unordered_map<std::string, std::shared_ptr<BookRecord>>::iterator _node;
    std::ofstream _outputFile;
};

Book::Book(std::string OutFileName):
    _outputFile(OutFileName)
{}

Book::~Book()
{
    _outputFile.close();
}

void Book::updateBook()
{
    if (findRecord())
    {
        if (_node->second->MaxTimeGap == 0)
            _node->second->MaxTimeGap = *_timeStamp - *_node->second->TimeStamp;
        else
            _node->second->MaxTimeGap = std::max(_node->second->MaxTimeGap, (*_timeStamp - *_node->second->TimeStamp));
        _node->second->MaxPrice = std::max(_node->second->MaxPrice, *_price);
        _node->second->PriceQuantity += (*_price * *_quantity);
        _node->second->Volume += *_quantity;
        _node->second->WeightedAveragePrice = static_cast<int>(_node->second->PriceQuantity/_node->second->Volume);
        _node->second->Price = _price;
        _node->second->Quantity = _quantity;
        _node->second->Symbol = _symbol;
        _node->second->TimeStamp = _timeStamp;
    }
    else
        addRecord();
}

void Book::outputBook()
{
    if (_outputFile.is_open())
    {
        std::set<std::string> keys;
        for (const auto &pair : _bookMap)
        {
            keys.insert(pair.first);
        }
        for (auto& key : keys) {
            _outputFile << _bookMap[key]->getLine();
        }
    }
}

bool Book::findRecord()
{
    _node = _bookMap.find(*_symbol);
    if (_node != _bookMap.end())
        return true;
    return false;
}

void Book::addRecord()
{
    std::shared_ptr<BookRecord> bRecord = std::make_shared<BookRecord>();
    bRecord->MaxPrice = *_price;
    bRecord->Price = _price;
    bRecord->PriceQuantity = *_price * *_quantity;
    bRecord->Quantity = _quantity;
    bRecord->Symbol = _symbol;
    bRecord->TimeStamp = _timeStamp;
    bRecord->MaxTimeGap = 0;
    bRecord->Volume = *_quantity;
    bRecord->WeightedAveragePrice = static_cast<int>(bRecord->PriceQuantity / bRecord->Volume);

    _bookMap.insert(std::make_pair(*_symbol, bRecord));
}

void Book::registerValue(Symbol & smbl)
{
    _symbol = smbl.getValue();
}

void Book::registerValue(TimeStamp & ts)
{
    _timeStamp = ts.getValue();
}
void Book::registerValue(Quantity & qty)
{
    _quantity = qty.getValue();
}

void Book::registerValue(Price & price)
{
    _price = price.getValue();
}