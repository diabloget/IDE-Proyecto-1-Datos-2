/**
 * @file MemoryObject.cpp
 * @authors Diabloget, Jjvv21
 */

#include "MemoryObject.h"
/**
 * @class MemoryObject
 * @brief Permite crear MemoryObjects
 * @details Almacena propiedades de variables recibidas del servidor en formato Json como objetos MemoryObject para acceder a sus propiedades facilmente.
 * @public
 */

/**
 * @brief Constructor de objeto MemoryObject
 * @param string memDirect
 * @param string name
 * @param string value
 * @param string constant
 * @param string scope
 * @details Constructor del MemoryObject para convertir los Json del servidor en MemoryObjects y tener acceso a las propiedades de la memoria para el LiveRamViewer
 */
MemoryObject::MemoryObject(std::string memDirect, std::string name, std::string value, std::string constant, std::string scope){
    this->memDirect = memDirect;
    this->name = name;
    this->value = value;
    this->constant = constant;
    this->scope = scope;
}