//
// Created by idan on 19/01/2020.
//

#ifndef EX4_STATE_INFO_H
#define EX4_STATE_INFO_H

#include "State.h"
struct state_info {
private:
    int row, col;
public:
    state_info() {}

    state_info(int _row, int _col) {
        row = _row;
        col = _col;
    }
    //get the row of a node
    int getR() {
        return row;
    }
    //get the column of a node
    int getC() {
        return col;
    }
    //operator ==
    bool operator==(state_info other) {
        if (this->col == other.col && this->row == other.row) {
            return true;
        }
        return false;
    }
};

typedef State<state_info> this_state;


#endif //EX4_STATE_INFO_H
