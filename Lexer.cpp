/**
 * @file Lexer.cpp
 * @authors Diabloget, Jjvv21
 */

#include "Lexer.h"
/**
 * @class Lexer
 * @brief Clase lexer para descomponer y verificar texto
 * @details Lexer verifica el texto ingresado para detectar una gramatica definica, con el fin de reaccionar a instrucciones escritas.
 * @public
 */

/**
 * @brief Constructor de lexer
 * @details Constructor del lexer y inicializador del decomposer y el texto para el print.
 */
Lexer::Lexer(){
    decomposer = Decomposer();
    printText = "";
    //printer = Printer();
}

/**
 * @brief Escritor de archivos
 * @param string name
 * @param string text
 * @details Abre segun nombre un archivo, escribe en el y lo cierra. Si el archivo no existe, lo crea.
 */
void Lexer::write(std::string name, std::string text){
    std::ofstream file_;
    file_.open(name);
    if(file_.is_open()){
        file_ << text;
    }
    printText.append("Saving code on text file\n");
    file_.close();
}

/**
 * @brief get de la string printText
 * @return string printText
 * @details Retorna el texto al que se le agregan los logs de la consola.
 */
std::string Lexer::getPrintText(){
    return printText;
    return "";
}

std::string Lexer::getPrintText2(){
    return printText2;
    return "";
}

/**
 * @brief set del string printText
 * @param string toadd
 * @details agrega texto al final de la string printText usado en el log de consola.
 */
void Lexer::setPrintText(std::string toadd){
    printText.append(toadd);
}


void Lexer::setPrintVector(std::vector<MemoryObject> vector){
    printer.setMemVector(vector);
}

/**
 * @brief Lee un archivo y lo tokeniza.
 * @param string name
 * @details Lex recibe el nombre de un archivo y descompone el texto para analizar la gramatica y identificar instrucciones (Metodo Lexer).
 */
void Lexer::lex(std::string name){
    //decomposer = Decomposer();

    std::ifstream file(name);
    std::string content;

    std::string id = "([a-zA-Z]+)";
    std::string number = "([0-9]+)";
    std::string assignValue = "(" + number + "|" + id + "|" + "'" + id + "'" + ")";
    std::string operadores = "(\\+|\\-|\\*|\\/)";
    std::string operation = "(" + assignValue + "((\\s)*" +operadores + "(\\s)*"+ assignValue + ")*)";

    std::regex regIntOper ("(int)\\s" + id + "(\\s)*(=)(\\s)*" + operation +";(\\n)*");
    std::regex regLongOper ("(long)\\s" + id + "(\\s)*(=)(\\s)*" + operation +";(\\n)*");
    std::regex regCharOper ("(char)\\s" + id + "(\\s)*(=)(\\s)*" + operation +";(\\n)*");
    std::regex regFloatOper ("(float)\\s" + id + "(\\s)*(=)(\\s)*" + operation +";(\\n)*");
    std::regex regDoubleOper ("(double)\\s" + id + "(\\s)*(=)(\\s)*" + operation +";(\\n)*");
    //std::regex regPrint ("(print)\\s" + id + "|" + number + ";(\\n)*");
    std::regex regPrint ("(print)\\s" + number + ";(\\n)*");
    std::regex regOpenScope ("\\{");
    std::regex regCloseScope ("\\}");

    int lines = 0;
    int scope = 0;
    server = Sender();
    server.initServer();

    while(getline(file,content)) {
        lines++;
        //std::cout << content << "\n";

        if (std::regex_match(content, regIntOper)) {
            std::cout << "Text is a int operation\n";
            printText.append("Line recognized as a int operation\n");
            decomposer.dec(content, 4, "int", scope, lines);
        }else if (std::regex_match(content, regLongOper)) {
            std::cout << "Text is a long operation\n";
            printText.append("Line recognized as a long operation\n");
            decomposer.dec(content, 5, "long", scope, lines);
        }else if (std::regex_match(content, regCharOper)) {
            std::cout << "Text is a char operation\n";
            printText.append("Line recognized as a char operation\n");
            decomposer.dec(content, 5, "char", scope, lines);
        }else if (std::regex_match(content, regFloatOper)) {
            std::cout << "Text is a float operation\n";
            printText.append("Line recognized as a float operation\n");
            decomposer.dec(content, 6, "float", scope, lines);
        }else if (std::regex_match(content, regDoubleOper)) {
            std::cout << "Text is a double operation\n";
            printText.append("Line recognized as a double operation\n");
            decomposer.dec(content, 7, "double", scope, lines);
        }else if (std::regex_match(content, regPrint)) {
            std::cout << "Line recognized as a print function\n";
            printText.append("Line recognized as a print function\n");
            //printText2.append(content);
            //printText2.append("Nani");
            //std::cout << printText << "\n";
        }else if (std::regex_match(content, regOpenScope)){
            scope++;
        }else if (std::regex_match(content, regCloseScope)){
            if(scope!=0){
                scope--;
            }else{
                std::cout << "Error: Wrong closed scope\n";
            }
        }else {
            std::cout << "Error: Something can't be lexed\n";
            printText.append("Grammatical Error: something could not be lexed in the past line!\n");
        }

    }
    file.close();
    std::cout << "despues while" << "\n";


}