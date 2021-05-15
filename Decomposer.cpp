/**
 * @file Decomposer.cpp
 * @authors Diabloget, Jjvv21
 */

#include "Decomposer.h"
std::vector<Instruction> vector;

/**
 * @class Decomposer
 * @brief Descompone el texto en instrucciones.
 * @public
 * @details Decomposer convierte instrucciones textuales en el objeto instruccion para accesar con mayor facilidad a los datos de cada linea de codigo escrita.
 */

/**
 * @brief Constructor de Decomposer
 * @details Inicializa el vector de instrucciones.
 */
Decomposer::Decomposer(){
    vector = std::vector<Instruction>();
}

/**
 * @brief Descompone lineas en instrucciones
 * @param string line
 * @param int start
 * @param string type
 * @param int scope
 * @param int linenumber
 * @details dec actua como un pseudo parser, descompone los comandos escritos del archivo de texto en instrucciones.
 */
void Decomposer::dec(std::string line, int start, std::string type, int scope, int linenumber){
    std::string oper1 = "";
    std::string oper = "";
    std::string oper2 = "";
    std::string ident = "";
    std::regex regOper ("(\\+|\\-|\\*|\\/)");
    int index;
    for (int i = start; i < line.size(); i++) {
        if (line[i] == '=') {
            index = i+1;
            break;
        }else if (line[i] == ' '){
            index = i;
            while(line[index] == ' '){
                index++;
            }
            index++;
            break;
        }
        ident.push_back(line[i]);
    }
    bool flag = false;
    for(int i = index; i < line.size(); i++){
        if(line[i]== ';'){
            flag = true;
            break;
        }else if(line[i] == '/'){
            oper = line[i];
            index = i+1;
            break;
        }else if(line[i] == '+'){
            oper = line[i];
            index = i+1;
            break;
        }else if(line[i] == '-'){
            oper = line[i];
            index = i+1;
            break;
        }else if(line[i] == '*'){
            oper = line[i];
            index = i+1;
            break;
        }else if(line[i] != ' '){
            oper1.push_back(line[i]);
        }
    }

    while(line[index] == ' '){
        index++;
    }
    while(line[index]!=';'){
        oper2.push_back(line[index]);
        index++;
    }
    //oper2 = line.substr(index,line.size()-1);

    std::cout << "Oper1 es " <<oper1 << "\n";
    std::cout << "Oper2 es " <<oper2 << "\n";
    std::cout << "Oper es " <<oper << "\n";

    //std::cout << ident << "\n";



    if(flag){
        Instruction ins = Instruction(type, oper1, ident, scope, linenumber);
        vector.push_back(ins);
    }else{
        Instruction ins = Instruction(type, oper1, oper, oper2, ident, scope, linenumber);
        vector.push_back(ins);
    }

}


void Decomposer::scopeManager(int scope){
    Instruction ins = Instruction("scope",  scope);
    vector.push_back(ins);
}

/**
 * @brief Retorna instrucion en formato json
 * @param vecIndex
 * @return string json
 * @details Llama al metodo JsonCreator de la instruccion para convertirla en string y la retorna.
 */
std::string Decomposer::readLine(int vecIndex){
    return vector[vecIndex].JsonCreator();
}