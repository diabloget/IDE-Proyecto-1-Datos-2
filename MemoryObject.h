//
// Created by diabloget on 5/10/21.
//

#ifndef IDE_MEMORYOBJECT_H
#define IDE_MEMORYOBJECT_H
#include <iostream>


class MemoryObject {
public:
    std::string memDirect;
    std::string name;
    std::string value;
    std::string constant;
    std::string scope;

    MemoryObject(std::string memDirect, std::string name, std::string value, std::string constant, std::string scope);
};

#endif //IDE_MEMORYOBJECT_H
