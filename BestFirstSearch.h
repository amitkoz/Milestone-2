//
// Created by idan on 10/01/2020.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H


#include <queue>
#include <set>
#include "Searchable.h"
#include "Searcher.h"
#include "priorityQ.h"


class BestFirstSearch : public Searcher {

public:
    vector<this_state *> search(Searchable<this_state> *searchable) override;
};



#endif //EX4_BESTFIRSTSEARCH_H
