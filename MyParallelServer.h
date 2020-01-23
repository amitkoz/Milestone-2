#ifndef SECONDPART_MYPARALLELSERVER_H
#define SECONDPART_MYPARALLELSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <pthread.h>
#include <iostream>
#include <queue>
#include <map>

#include "Server.h"

class MyParallelServer : public server_side::Server{
private:
    queue<thread> t;
public:
    void open(int portNum, ClientHandler *c) override;
    static void solveIt(int cSock,ClientHandler *c);
    void stop() override {
        flag = 0;
    }
    ~MyParallelServer() {}

};

#endif