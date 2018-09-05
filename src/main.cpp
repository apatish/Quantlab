#include <string>
#include <vector>
#include <iostream>
#include "CommandLineArgs.h"
#include "ExchangeDataProcessor.h"
#include "ReadFromCSV.h"
#include "Book.h"

int main(int argc, char*argv[])
{
    if (argc < 3)
    {
        std::cout << "Please suply input and output file names" << std::endl;
        return -1;
    }
    CommandLineArgs cla(argc, argv);
    Book  book(cla.getArgsArr()->at(1));
    ReadFromCSV fileParcer(cla.getArgsArr());
    ExchangeDataProcessor<ReadFromCSV> exchDtaPrsr(fileParcer, book);
    exchDtaPrsr.run();
    book.outputBook();
    return 0;
}

