#include <iostream>
#include "BestFirstSearch.h"
vector<this_state *> BestFirstSearch::search(Searchable<this_state> *searchable) {
    //set all data
    this_state *trg = searchable->getGoal();
    vector<this_state *> adj;
    BestPriorutyQ OPEN;
    set<this_state *> CLOSED;
    this_state *s = searchable->getStart();
    s->setColor("grey");
    s->setMinPath(0);
    OPEN.push(s);
    s->setMinPath(s->getEdgeCost());
    //check amount of objects in the container
    while (OPEN.size() > 0) {
        s = OPEN.top();
        OPEN.pop();
        CLOSED.insert(s);
        //check if this nose is target node
        if (s == trg) {
            return getPath(searchable->getGoal());
        }
        adj = searchable->getAllPossibleStates(*s);
        //check all neighbors
        for (auto &v : adj) {
            if (v->getColor() == "white") {
                v->setCameFrom(s);
                //update value
                v->setMinPath(s->getMinPath() + v->getEdgeCost());
                v->setColor("grey");
                OPEN.push(v);
            } else if (v->getColor() == "grey") {
                if (v->getMinPath() > s->getMinPath() + v->getEdgeCost()) {
                    v->setMinPath(s->getMinPath() + v->getEdgeCost());
                    v->setCameFrom(s);
                    BestPriorutyQ tempo = OPEN;
                    while (!OPEN.empty()) {
                        tempo.push(OPEN.top());
                        OPEN.pop();
                    }
                    OPEN = tempo;
                }
            }
        }
        //update the amount of operation
        ++evaluatedNodes;
    }
}
