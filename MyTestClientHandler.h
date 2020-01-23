#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H

#include <string>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <algorithm>
#include "Solver.h"
#include "CacheManager.h"
#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
private:
    Solver<string, string> *solver;
    CacheManager<string,string> *cm;
public:

    MyTestClientHandler(Solver<string, string> *_solver, CacheManager<string,string> *_cm) : solver(_solver), cm(_cm) {}
    //get data from client,return the data as string
    string getDate(int client_socket) {
        char buffer[1024] = {0};
        while (1) {
            int val = read(client_socket, buffer, 1024);
            if (val < 0) {
                perror("error");
                exit(3);
            }
            string s = buffer;
            s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());
            s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
            return s;
        }
    }
    //the method that handle the client
    string handleClient(int client_socket) {
        string answer;
        vector<string> vec;
        string s =getDate(client_socket);
        vec.push_back(s);
        if (s.compare("end")==0) {
            close(client_socket);
        } else {
            //cheack if the solution is exist
            if (cm->isExists(vec)) {
                //send massege
                cm->save(vec,cm->getSolve(vec));
                answer= cm->getSolve(vec)+ "\r\n";
                char const *msg = answer.c_str();
                send(client_socket, msg, strlen(msg), 0);
            } else {
                //calculate the answer
                cm->save(vec, solver->solve(*vec.begin()));
                answer= solver->solve(*vec.begin())+ "\r\n";
                char const *msg = answer.c_str();
                //send the answer
                send(client_socket, msg, strlen(msg), 0);
            }
        }
    }

    ~MyTestClientHandler() {}
};

#endif //EX4_MYTESTCLIENTHANDLER_H
