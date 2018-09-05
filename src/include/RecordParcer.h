#pragma once
#include <cstdarg>

template<typename BookType, typename RecordType,typename ...OutputParams>
class RecordParser
{
public:
    RecordParser()  {}
    ~RecordParser() {}
    virtual bool parceRecord(RecordType record, BookType & book, OutputParams... outputParams) = 0; 
};