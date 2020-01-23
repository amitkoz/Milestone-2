//
// Created by idan on 07/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "MatrixSearchable.h"
#include "Searchable.h"

using namespace std;
class Searcher {
protected:
    int evaluatedNodes =0;
public:
    virtual vector<this_state *> search(Searchable<this_state> *searchable)  = 0;
    virtual vector<this_state *> getPath(this_state *trg){
        vector<this_state *> getP;
        while (trg->getCameFrom() != nullptr) {
            getP.push_back(trg);
            trg = trg->getCameFrom();
        }
        getP.push_back(trg);
        return getP;
    }
    virtual ~Searcher() {}
};


#endif //EX4_SEARCHER_H
