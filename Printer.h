//
// Created by diabloget on 5/12/21.
//

#ifndef IDE_PRINTER_H
#define IDE_PRINTER_H
#include <iostream>
#include <QTextEdit>
#include "MemoryObject.h"


class Printer {
public:
    //static QTextEdit *Log1;

    Printer();
    std::vector<MemoryObject> vecMem;
    void setMemVector(std::vector<MemoryObject> pepito);
    std::string print(std::string toPrint);
};


#endif //IDE_PRINTER_H
