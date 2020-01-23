#ifndef EX4_DFS_H
#define EX4_DFS_H
#include "priorityQ.h"
#include "Searcher.h"
#include "MatrixSearchable.h"
#include <bits/stdc++.h>
class DFS : public Searcher {
private:
    Searchable<this_state> *searchable;
public:
    vector<this_state *> search(Searchable<this_state> *searchable) override;
};
#endif //EX4_DFS_H
