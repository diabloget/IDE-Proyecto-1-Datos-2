//
// Created by diabloget on 5/10/21.
//

#ifndef IDE_LEXER_H
#define IDE_LEXER_H
#include <iostream>
#include <fstream>
#include <regex>
#include <QJsonObject>
#include <QJsonDocument>
#include "Sender.h"
#include "Decomposer.h"
#include "Printer.h"
#include "MemoryObject.h"

//#include "Window.h"


class Lexer {
public:
    Sender server;

    Decomposer decomposer;
    Lexer();
    void write(std::string name, std::string text);
    void lex(std::string name);
    std::string getPrintText();
    std::string getPrintText2();
    Printer printer;
    //static QTextEdit *Log1;
    std::string printText;
    std::string printText2;
    void setPrintVector(std::vector<MemoryObject> vector);
    void setPrintText(std::string toadd);
};


#endif //IDE_LEXER_H
