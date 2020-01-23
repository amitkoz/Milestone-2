#ifndef EX4_STATE_H
#define EX4_STATE_H
using namespace std;
template<class T>
class State {
    T stateId;
    double edgeCost;
    double minPath;
    State<T> *cameFrom;
    string color;
public:
    // state constructor
    State(const T &_stateId, double cost) :stateId(_stateId) {
        edgeCost = cost;
        cameFrom = nullptr;
        minPath = -1;
        color = "white";
    }
   // return this state
    T getStateId() const {
        return stateId;
    }
    //return the cost of the edge
    double getEdgeCost() {
        return edgeCost;
    }
    //set the value of the minimum path
    void setMinPath(double _minPath) {
        minPath = _minPath;
    }
    //return the minimum path
    int getMinPath() {
        return minPath;
    }
    //return the "father" of a node
    State<T> *getCameFrom() {
        return cameFrom;
    }
    // set the "father of a node
    void setCameFrom(State<T> *_cameFrom) {
        cameFrom = _cameFrom;
    }
    // set the color of a node
    void setColor(string _color) {
        color =  _color;
    }
    //return the color of a node
    string getColor() {
        return color;
    }
};

#endif