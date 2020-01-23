#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
using namespace std;
template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem) = 0;
    virtual ~Solver() {}
};

#endif //EX4_SOLVER_H
