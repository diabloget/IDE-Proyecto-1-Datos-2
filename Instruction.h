//
// Created by diabloget on 5/10/21.
//

#ifndef IDE_INSTRUCTION_H
#define IDE_INSTRUCTION_H
#include <iostream>
#include <QJsonObject>
#include <QJsonDocument>
#include "Sender.h"

class Instruction {
public:
    std::string type;
    std::string oper1;
    std::string oper;
    std::string oper2;
    std::string identifier;
    int scope;
    int line;
    Instruction(std::string type, std::string oper1, std::string oper, std::string oper2, std::string identifier, int scope, int line);
    Instruction(std::string type, std::string oper1, std::string identifier, int scope, int line);
    Instruction(std::string type, int scope);
    std::string JsonCreator();

};


#endif //IDE_INSTRUCTION_H
