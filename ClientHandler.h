#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <string>

using namespace std;
class ClientHandler {
public:
    virtual  string handleClient(int client_socket) = 0;
    virtual ~ClientHandler() {}
};

#endif
