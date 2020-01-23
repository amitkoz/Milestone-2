#ifndef EX4_MAIN_H
#define EX4_MAIN_H

#include <string>
#include <vector>
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "MatrixSearchable.h"
#include "MatrixSolver.h"
#include "MyClientHandler.h"
#include "Astar.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "FileCacheManager.h"

namespace boot {
    class Main {
    public:
        void main(int port) {
            //create server
            Server* server= new MyParallelServer();
            //create object of the chosen algorithm
            Searcher* astar = new Astar();
            //create a solver object with the option to solve matrix
            Solver<Searchable<this_state>*,vector<this_state*> >* solver = new MatrixSolver(astar);
            // create cache manager object
            CacheManager<string,string>* cm = new FileCacheManager<string,string>();
            // create an object to handle the client
            ClientHandler* clientHandler = new MyClientHandler(solver,cm);
            server->open(port,clientHandler);
            //delete data from heap
            delete server;
            delete astar;
            delete solver;
            delete cm;
            delete clientHandler;
        }
    };
}
#endif //EX4_MAIN_H
