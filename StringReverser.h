#include <string>
#include <iostream>
#include "Solver.h"

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H



class StringReverser : public Solver<string,string> {
public:
    string solve(string str1);
};


#endif //EX4_STRINGREVERSER_H