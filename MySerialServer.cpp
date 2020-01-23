#include "MySerialServer.h"

void MySerialServer::solveProb(int portNum, ClientHandler *c) {
    //open server
    int server = socket(AF_INET, SOCK_STREAM, 0);
    if (server == -1) {
        cerr << "can't open server" << endl;
        exit(1);
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(portNum);
    if (bind(server, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << "can't bind server" << endl;
        exit(1);
    }
    //can listening to 10 clients
    if (listen(server, 10) == -1) {
        cerr << "can't listen server" << endl;
        exit(1);
    }
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);
    //run until we stop you or until time out
    while (flag) {
        cout << "waiting for a client..." << std::endl;
        //checking timeout
        timeval timeout;
        timeout.tv_sec = 120;
        timeout.tv_usec = 0;
        setsockopt(server, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        int client_socket = accept(server, (struct sockaddr *) &client, &clilen);
        if (client_socket < 0) {
            if (errno == EWOULDBLOCK) {
                cerr << "timeout!" << std::endl;
                close(client_socket);
                break;
            } else {
                cerr << "connection error" << endl;
                exit(1);
            }
        }
        cout << "There is a connection..." << std::endl;
        //open a thread, and handle the client until he get the answer
        c->handleClient(client_socket);
        //close the socket after handling
        close(client_socket);
    }
    //close server
    close(server);
}
//open a thread for a client
void MySerialServer::open(int portNum, ClientHandler *c) {
    thread thread1(solveProb, portNum, c);
    thread1.join();
}
