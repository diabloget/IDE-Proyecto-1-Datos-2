/**
 * @file Sender.cpp
 * @authors Diabloget, Jjvv21
 */
#include "Sender.h"

int opt = 1;
/**
 * @class Sender
 * @brief Instancia del servidor.
 * @details Clase servidor para instanciar los sockets.
 */

/**
 * @brief Constructor de Sender
 * @details Permite construir el objeto Sender para asi llamar a los metodos de los sockets.
 */
Sender::Sender(){
}

/**
 * @brief Envia Json al servidor.
 * @param Json
 * @return string Json
 * @details Envia Json de instruccion al servidor y retorna el Json respuesta.
 */
std::string Sender::startServer(std::string Json){
    char cstr[Json.size() + 1];
    strcpy(cstr, Json.c_str());

    //Socket principal
    if ((servidor = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (connect(servidor, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }
    send(servidor , cstr , strlen(cstr) , 0 );
    close(servidor);

    if ((servidor = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(servidor, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(servidor, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("%s\n","Waiting" );
    bool end = false;
    int clientConection;
    int addrlen = sizeof(address);
    bzero(buffer,1024);
    do{
        if ((clientConection = accept(servidor, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        int readLen = read(clientConection , buffer, 1024);
        if (readLen > 0){
            printf("%s\n",buffer);
            end = true;
        }
        close(clientConection);
    } while(!end);

    close(servidor);
    std::string x = buffer;
    return x;
}

/**
 * @brief Inicia el servidor
 * @details Envia el mensaje init para asi preparar al socket del servidor para recibir instrucciones.
 */
void Sender::initServer(){
    char *ok = "init";

    //Socket principal
    if ((servidor = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (connect(servidor, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }
    send(servidor , ok , strlen(ok) , 0 );
    close(servidor);
}