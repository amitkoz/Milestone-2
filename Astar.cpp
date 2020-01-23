#include <iostream>
#include "Astar.h"

vector<this_state *> Astar::search(Searchable<this_state> *searchable) {
    //set all data
    AstarPriorityQueue q;
    double path;
    vector<this_state *> adj;
    this_state *s = searchable->getStart();
    this->trg = searchable->getGoal();
    s->setMinPath(s->getEdgeCost());
    s->setColor("grey");
    path = s->getMinPath() + sqrt(pow(s->getStateId().getR() - trg->getStateId().getR(), 2) +
                                  pow(s->getStateId().getC() - trg->getStateId().getC(), 2));
    q.push(pair<this_state *, double>(s, path));
    //check amount of objects in the container
    while (q.size() > 0) {
        s = q.top().first;
        q.pop();
        //check if this nose is target node
        if (s == this->trg) {
            return getPath(this->trg);
        }
        adj = searchable->getAllPossibleStates(*s);
        //check all neighbors
        for (auto &v : adj) {
            if (v->getColor() == "white") {
                v->setMinPath(s->getMinPath() + v->getEdgeCost());
                v->setColor("grey");
                v->setCameFrom(s);
                //update value
                path = v->getMinPath() + sqrt(pow(v->getStateId().getR() - trg->getStateId().getR(), 2) +
                                              pow(v->getStateId().getC() - trg->getStateId().getC(), 2));
                q.push(pair<this_state *, double>(v, path));
            } else if (v->getColor() == "grey") {
                if (v->getMinPath() > s->getMinPath() + v->getEdgeCost()) {
                    v->setMinPath(s->getMinPath() + v->getEdgeCost());
                    v->setCameFrom(s);
                    AstarPriorityQueue newQ;
                    while (!q.empty()) {
                        if (q.top().first->getStateId() == v->getStateId()) {
                            //update value
                            path = v->getMinPath() + sqrt(pow(v->getStateId().getR() - trg->getStateId().getR(), 2) +
                                                          pow(v->getStateId().getC() - trg->getStateId().getC(), 2));
                            newQ.push(pair<this_state *, double>(v, path));
                            q.pop();
                        } else {
                            newQ.push(q.top());
                            q.pop();
                        }
                    }
                    q = newQ;
                }
            }
        }
        //update the amount of operation
        ++evaluatedNodes;
        s->setColor("black");
    }
}
