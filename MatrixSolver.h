#ifndef EX4_MATRIXSOLVER_H
#define EX4_MATRIXSOLVER_H

#include "Searcher.h"
#include "Solver.h"
#include "Searchable.h"
#include "MatrixSearchable.h"
class MatrixSolver : public Solver<Searchable<this_state> *, vector<this_state *>> {
        private:
        Searcher *searcher;
        public:
        MatrixSolver(Searcher *_searcher) : searcher(_searcher) {}
        // call to the function that solve our problem
        vector<this_state *> solve(Searchable<this_state> *searchable) override {
            return searcher->search(searchable);
        }
        ~MatrixSolver() {}
};

#endif //EX4_MATRIXSOLVER_H

