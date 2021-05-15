

#include "Printer.h"

Printer::Printer(){
}
void Printer::setMemVector(std::vector<MemoryObject> pepito){
    vecMem = pepito;
}

std::string Printer::print(std::string toPrint){
    int a;
    try {
        a = std::stoi(toPrint);
        //Window().printOnConsole(to_string(a) + "\n");
        return (std::to_string(a) + "\n");
    } catch (std::invalid_argument){
        //print "Print error, argument does not exist or is a grammatical error"
        //Window().printOnConsole("Print error, argument does not exist or is a grammatical error");
        return "Print error, fail getting argument or is a grammatical error\n";
    }
}
/*
std::string Printer::print(std::string toPrint){
    int a;
    for(int i = 0; i<vecMem.size();i++){
        if(vecMem[i].name == toPrint){
            //Window().printOnConsole(lexito.memObjVector[i].value + "\n");

            return vecMem[i].value + "\n";
            //for(int i = 0; )
        } else {
            try {
                a = std::stoi(toPrint);
                //Window().printOnConsole(to_string(a) + "\n");
                return (std::to_string(a) + "\n");
            } catch (std::invalid_argument){
                //print "Print error, argument does not exist or is a grammatical error"
                //Window().printOnConsole("Print error, argument does not exist or is a grammatical error");
                return "Print error, fail getting argument or is a grammatical error\n";
            }
        }
    }

}
 */