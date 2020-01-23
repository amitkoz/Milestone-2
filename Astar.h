#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#include <queue>
#include <cmath>
#include "Searcher.h"
#include "Searchable.h"
#include "priorityQ.h"


class Astar : public Searcher {
private:
    this_state *trg;
public:
    vector<this_state *> search(Searchable<this_state> *searchable) override;
};
#endif
