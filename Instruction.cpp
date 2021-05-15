/**
 * @file Instruction.cpp
 * @authors Diabloget, Jjvv21
 */


#include "Instruction.h"
#include "Lexer.h"

/**
 * @class Instruction
 * @brief Almacena instrucciones.
 * @details La clase Instruction permite crear objetos de instruccion para almacenar los datos de cada instruccion de forma ordenada.
 * @public
 */

/**
 * @brief Constructor de Instruction
 * @param type
 * @param oper1
 * @param oper
 * @param oper2
 * @param identifier
 * @param scope
 * @param line
 * @details Constructor de instrucciones con multiples operadores y operaciones.
 */
Instruction::Instruction(std::string type, std::string oper1, std::string oper, std::string oper2, std::string identifier, int scope, int line){
    this->type = type;
    this->oper1 = oper1;
    this->oper = oper;
    this->oper2 = oper2;
    this->identifier = identifier;
    this->scope = scope;
    this->line = line;
}

/**
 * @brief Constructor de Instruction
 * @param type
 * @param oper1
 * @param identifier
 * @param scope
 * @param line
 * @details Constructor de instruccion con un unico operador.
 */
Instruction::Instruction(std::string type, std::string oper1, std::string identifier, int scope, int line){
    this->type = type;
    this->oper1 = oper1;
    this->identifier = identifier;
    this->scope = scope;
    this->line = line;
}
Instruction::Instruction(std::string type, int scope){
    this->type = type;
    this->scope = scope;
}

/**
 * @brief JsonCreator convierte instrucciones en Json
 * @return server.start(string Json)
 * @details Jsoncreator llama al server para enviar la instruccion en formato Json para almacenarla en memoria del lado del server.
 */
std::string Instruction::JsonCreator(){
    QJsonObject newJson = QJsonObject();
    newJson.insert("type",QString::fromStdString(type));
    newJson.insert("oper1",QString::fromStdString(oper1));
    newJson.insert("oper",QString::fromStdString(oper));
    newJson.insert("oper2",QString::fromStdString(oper2));
    newJson.insert("identifier",QString::fromStdString(identifier));
    newJson.insert("scope",QString::fromStdString(std::to_string(scope)));
    newJson.insert("line",QString::fromStdString(std::to_string(line)));

    QJsonDocument doc(newJson);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    std::cout << strJson.toStdString();
    //Lexer().setPrintText("Sending Json: " + strJson.toStdString() + "\n");

    Sender sendersito = Sender();
    return sendersito.startServer(strJson.toStdString());
}