#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "ClientHandler.h"
#include "Server.h"
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <arpa/inet.h>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <pthread.h>

using namespace std;
static int flag =1;
namespace server_side {
    class Server {
    protected:
    public:
        virtual void open(int port, ClientHandler *c) = 0;
        virtual void stop() = 0;
        virtual ~Server() {}
    };
}
#endif //EX4_SERVER_H
