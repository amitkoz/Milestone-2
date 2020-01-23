#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include <string>
#include <vector>
#include "State.h"
using namespace std;

template <class T>
class Searchable {
public:
    virtual T* getStart() = 0;
    virtual T* getGoal() = 0;
    virtual vector<T*> getAllPossibleStates(const T &s) = 0;
    virtual ~Searchable() {}
};

#endif