#include "MyParallelServer.h"

void MyParallelServer::open(int portNum, ClientHandler *c) {
    //open a server
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
    //can listening to 10 clients,at the same time
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
                break;
            } else {
                cerr << "connection error" << endl;
                exit(1);
            }
        }
        //make a new thread for each client that connect to our server
        cout << "There is a connection..." << endl;
        //push the thread to the queue
        t.push(thread(&MyParallelServer::solveIt,client_socket,c));
    }
    //if we quit the main loop,first handle the remain threads and then close server
    while (!t.empty()) {
        t.front().join();
        t.pop();
    }
    //close server
    close(server);
}
//a thread to handle a single client
void MyParallelServer::solveIt(int client_Socket,ClientHandler * c) {
    c->handleClient(client_Socket);
    //close socket
    close(client_Socket);
}
