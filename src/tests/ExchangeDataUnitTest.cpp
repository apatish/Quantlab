#include <iostream>
#include "TimeStamp.h"
#include "Symbol.h"
#include "Price.h"
#include "Quantity.h"

int main(int argc, char*argv[])
{
    bool      status(true);
    TimeStamp ts;
    Symbol    sbl;
    Price     price;
    Quantity  qty;
    if (!(status && !ts.parseValue("5130000017352")))
    {
        std::cerr << "TimeStamp error!" << std::endl;
    }
    if (!(status && !sbl.parseValue("bgfhk")))
    {
        std::cerr << "Symbol error!" << std::endl;
    }
    if (!(status && !price.parseValue("-113")))
    {
        std::cerr << "Price error!" << std::endl;
    }
    if (!(status && !qty.parseValue("-175")))
    {
        std::cerr << "Quantity error!" << std::endl;
    }
    return status;
}