#pragma once
#include <sstream>
#include <tuple>
#include <initializer_list>
#include "RecordParcer.h"
#include "TimeStamp.h"
#include "Symbol.h"
#include "Price.h"

template<typename BookType, typename RecordType, typename ...OutputParams>
class CSVlineParcer: public RecordParser<BookType,RecordType, OutputParams...>
{
public:
    CSVlineParcer(){}
    virtual ~CSVlineParcer(){}

    virtual bool parceRecord(RecordType record, BookType & book, OutputParams... outputParams)
    {
        bool status(true);
        std::stringstream input(*record);

        auto passValue = [&input, &status, &book](auto param)
        {
            std::string value;
            getline(input, value, ',');
            if (status && param.parseValue(value))
                book.registerValue(param);
        };
        (void)std::initializer_list<int> { (passValue(outputParams), 0)...};
        return status;
    }
};