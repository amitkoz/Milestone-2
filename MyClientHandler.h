#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include <string>
#include <stack>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <algorithm>
#include <iostream>
#include "Solver.h"
#include "CacheManager.h"
#include "ClientHandler.h"
#include "MatrixSearchable.h"

class MyClientHandler : public ClientHandler {
private:
    Solver<Searchable<this_state> *, vector<this_state *> > *solver;
    CacheManager<string, string> *cm;
public:

    MyClientHandler(Solver<Searchable<this_state> *, vector<this_state *>> *_solver, CacheManager<string, string> *_cm)
            : solver(_solver), cm(_cm) {}
    //get data from client
    string getLineFromSocket(int sockNum) {
        string line;
        char buffer[256] = {0};
        int n = read(sockNum, buffer, 256);
        if (n < 0) {
            cerr << "can't read data" << endl;
            exit(1);
        }
        line = buffer;
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        return line;
    }
    //get the matrix from client.
    vector<string> getMatrix(int socket, vector<string> matrix) {
        string matrixLine = getLineFromSocket(socket);
        while (matrixLine != "end") {
            matrix.push_back(matrixLine);
            matrixLine = getLineFromSocket(socket);
        }
        return matrix;
    }
    //make the answer to the client from vector we get.
    string fromStatesToStrings(vector<this_state *> path) {
        string answer;
        stack<string> directions;
        for (auto &curr : path) {
            if (curr->getCameFrom() == nullptr) {
                break;
            }
            if (curr->getStateId().getR() == curr->getCameFrom()->getStateId().getR()) {
                if (curr->getStateId().getC() > curr->getCameFrom()->getStateId().getC())
                    directions.push("Right(" + to_string(curr->getMinPath()) + "),");
                else
                    directions.push("Left(" + to_string(curr->getMinPath()) + "),");

            } else {
                if (curr->getStateId().getR() > curr->getCameFrom()->getStateId().getR())
                    directions.push("Down(" + to_string(curr->getMinPath()) + "),");

                else
                    directions.push("Up(" + to_string(curr->getMinPath()) + "),");

            }

        }
        while (!directions.empty()) {
            string token = directions.top();
            directions.pop();
            answer += token;
        }
        return answer.substr(0, answer.length() - 1);
    }
   //the method that handle the client
    string handleClient(int socket) {
        vector<string> matrix;
        string answer;
        //get matrix
        matrix = getMatrix(socket, matrix);
        //check if exist in cache
        if (cm->isExists(matrix)) {
            //if so, get the answer
            answer = cm->getSolve(matrix);
        } else {
            //calculate the answer
            Searchable<this_state> *maze = new MatrixSearchable(matrix);
            vector<this_state *> states = solver->solve(maze);
            if (states.at(0)->getMinPath() == -1) {
                answer = "path not exist...";
            } else {
                answer = fromStatesToStrings(states);
            }
            cm->save(matrix, answer);
            delete maze;
        }
        //send the answer to the client
        int n = write(socket, answer.c_str(), answer.size());
        if (n < 0) {
            cerr << "can't read data" << endl;
            exit(1);
        }
    }

};


#endif //EX4_MYCLIENTHANDLER_H





