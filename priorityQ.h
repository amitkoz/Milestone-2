#ifndef EX4_PRIORITYQ_H
#define EX4_PRIORITYQ_H
#include <queue>
#include "MatrixSearchable.h"
using namespace std;
//priority queue the Asrar algorithm
struct AstarComparator {
    bool operator()(pair<this_state *, double> left, pair<this_state *, double> right) {
        return left.second > right.second;
    }
};

typedef priority_queue<std::pair<this_state *, double>, vector<pair<this_state *, double>>, AstarComparator>
AstarPriorityQueue;
//priority queue the Beat first search algorithm
struct Bestcomparator {
    bool operator()(this_state *left, this_state *right) {
        return left->getMinPath() > right->getMinPath();
    }
};

typedef std::priority_queue<this_state *, std::vector<this_state *>, Bestcomparator>
        BestPriorutyQ;

#endif //EX4_PRIORITYQ_H
