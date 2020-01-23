#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;
class MySerialServer : public Server {
public:
    void open(int portNum, ClientHandler *c);
    static void solveProb(int clientSocket, ClientHandler *c);

    void stop() {
        flag = 0;
    }

    ~MySerialServer() {

    }
};

#endif
