#pragma once
#include <string>
#include <sstream>
#include "TimeStamp.h"
#include "Symbol.h"
#include "Quantity.h"
#include "Price.h"
#include "Book.h"
#include "CSVlineParser.h"

template<typename Input>
class ExchangeDataProcessor
{
public:
    ExchangeDataProcessor() = delete;
    ExchangeDataProcessor(Input & inputData, Book & book):
        _inputData(&inputData),
        _book(&book)
    {
        _recordShrdPtr = std::make_shared<std::string>();
    };
    ~ExchangeDataProcessor() {};
    void run() 
    {
        while (_inputData->getRecord(_recordShrdPtr))
        {
            std::cout << _recordShrdPtr->c_str() << std::endl;
            if (_lineParser.parceRecord(_recordShrdPtr, *_book, _timeStamp, _symbol, _qty, _price))
                _book->updateBook();
            else
                std::cerr << "ERROR!!! Record was skipped." << std::endl;
        }
    }
private:
    Input                      * _inputData;
    std::shared_ptr<std::string> _recordShrdPtr;
    
    TimeStamp                    _timeStamp;
    Symbol                       _symbol;
    Quantity                     _qty;
    Price                        _price;
    Book                       * _book;

    CSVlineParcer<Book, std::shared_ptr<std::string>, TimeStamp, Symbol, Quantity, Price> _lineParser;
};