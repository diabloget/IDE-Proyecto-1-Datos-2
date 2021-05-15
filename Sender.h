//
// Created by diabloget on 5/9/21.
//

#ifndef IDE_SENDER_H
#define IDE_SENDER_H
#include <iostream>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

class Sender {
private:
    char buffer[1024];
    struct sockaddr_in address;
    int servidor;
    char *ok = "xx";
    char *ok1 = "ok1";

public:
    Sender();
    std::string startServer(std::string Json);
    void initServer();
};

#endif //IDE_SENDER_H
