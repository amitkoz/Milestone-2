#ifndef EX4_MATRIXSEARCHABLE_H
#define EX4_MATRIXSEARCHABLE_H

#include <sstream>
#include "Searchable.h"
#include "state_info.h"


class MatrixSearchable : public Searchable<this_state> {
    vector<vector<this_state *> > states;
    state_info src;
    state_info trg;
public:
    //constructor: create the matrix ,
    // represented by a vector of vector that contain strings, each string is a number
    MatrixSearchable(vector<string> data) {
        auto start = data.begin();
        auto end = --data.end();
        trg = getS_and_T(*end);
        --end;
        src = getS_and_T(*end);
        for (int rowNum = 0; start != end; ++start, ++rowNum) {
            saveMatrix(*start, rowNum);
        }
    }
    //get start and target states
    state_info getS_and_T(string &line) {
        stringstream ss(line);
        int row, col;
        char comma = ',';
        ss >> row >> comma >> col;
        state_info sttinf(row, col);
        return sttinf;
    }

    this_state *getStart() override {
        return states[src.getR()][src.getC()];
    }
    //return the goal state
    this_state *getGoal() override {
        return states[trg.getR()][trg.getC()];
    }
    // save the matrix
    void saveMatrix(string &row, int rowNum) {
        int colNum = 0;
        double cost;
        vector<this_state *> stateLine;
        stringstream ss(row);
        while (ss >> cost) {
            state_info id(rowNum, colNum);
            this_state *s = new this_state(id, cost);
            stateLine.push_back(s);
            if (ss.peek() == ',') {
                ss.ignore();
            }
            ++colNum;
        }
        states.push_back(stateLine);
    }
    //return vector with all node's neighbors
    vector<this_state *> getAllPossibleStates(const this_state &s) {
        vector<this_state *> adj;
        int colsNum = states.begin()->size();
        int rowsNum = states.size();
        int r = s.getStateId().getR();
        int c = s.getStateId().getC();
        if (r < rowsNum - 1 && states[r + 1][c]->getEdgeCost() != -1) {
            adj.push_back(states[r + 1][c]);
        }
        if (r > 0 && states[r - 1][c]->getEdgeCost() != -1) {
            adj.push_back(states[r - 1][s.getStateId().getC()]);
        }
        if (c < colsNum - 1 && states[r][c + 1]->getEdgeCost() != -1) {
            adj.push_back(states[r][c + 1]);
        }
        if (c > 0 && states[r][c - 1]->getEdgeCost() != -1) {
            adj.push_back(states[r][c - 1]);
        }
        return adj;
    }
    //delete data from heap
    ~MatrixSearchable() {
        for (auto x:states) {
            for (auto y:x) {
                if (y != NULL) {
                    delete y;
                }
            }
        }
    }
};

#endif //EX4_MATRIXSEARCHABLE_H

