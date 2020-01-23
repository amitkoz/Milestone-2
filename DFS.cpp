#include "DFS.h"

vector<this_state *> DFS::search(Searchable<this_state> *searchable) {
    //set all data
    BestPriorutyQ S;
    vector<this_state *> adj;
    this_state *trg = searchable->getGoal();
    S.push(searchable->getStart());
    //check amount of objects in the container
    while (S.size() > 0) {
        this_state * u = S.top();
        S.pop();
        //check if this nose is target node
        if (u == trg) {
            return getPath(u);
        }
        if (u->getColor().compare("white") == 0 ) {
            adj = searchable->getAllPossibleStates(*u);
            //check all neighbors
            for (auto &v : adj) {
                if (v->getColor().compare("white") == 0) {
                    S.push(v);
                    v->setCameFrom(u);
                    //update value
                    v->setMinPath(u->getMinPath() + v->getEdgeCost());
                }
            }
            //update the amount of operation
            ++evaluatedNodes;
            u->setColor("black");
        }
    }
}

