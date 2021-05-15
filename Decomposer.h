//
// Created by diabloget on 5/10/21.
//

#ifndef IDE_DECOMPOSER_H
#define IDE_DECOMPOSER_H


#include "Instruction.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <QJsonObject>
#include <QJsonDocument>
#include "Sender.h"

class Decomposer {
public:
    std::vector<Instruction> vector;
    Decomposer();
    void dec(std::string line, int start, std::string type, int scope, int linenumber);
    void scopeManager(int scope);
    std::string readLine(int vecIndex);
};


#endif //IDE_DECOMPOSER_H
