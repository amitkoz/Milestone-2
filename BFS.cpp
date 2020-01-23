#include "BFS.h"
vector<this_state *> BFS::search(Searchable<this_state> *searchable){
    //set all data
    this_state *s;
    queue<this_state *> Q;
    vector<this_state *> adj;
    this_state *trg = searchable->getGoal();
    s = searchable->getStart();
    s->setColor("grey");
    s->setMinPath(s->getEdgeCost());
    Q.push(s);
    //check amount of objects in the container
    while(Q.size()>0){
        s = Q.front();
        Q.pop();
        //check if this nose is target node
        if(s==trg){
            return getPath(s);
        }
        adj = searchable->getAllPossibleStates(*s);
        //check all neighbors
        for (auto &v : adj) {
            if(v->getColor().compare("white")==0){
                //update value
                v->setMinPath(s->getMinPath()+ v->getEdgeCost());
                Q.push(v);
                v->setCameFrom(s);
                v->setColor("grey");
            }
        }
        //update the amount of operation
        ++evaluatedNodes;
        s->setColor("black");
    }
}
