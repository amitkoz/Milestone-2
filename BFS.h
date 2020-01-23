#ifndef EX4_BFS_H
#define EX4_BFS_H
#include "Searcher.h"
#include "MatrixSearchable.h"
#include <bits/stdc++.h>
using namespace std;
class BFS: public Searcher {
public:
    vector<this_state *> search(Searchable<this_state> *searchable) override;
};
#endif //EX4_BFS_H
