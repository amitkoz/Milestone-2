#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "CacheManager.h"

template<class P, class S>
class FileCacheManager : public CacheManager<P, S> {
    map<string, S> mp;
    //hash the string to get unique name
    string hashIt(vector<P> Problem) {
        std::hash<string> mystdhash;
        string matrix = "";
        for (auto x: Problem) {
            matrix += x;
            matrix += "and";
        }
        auto num = mystdhash(matrix);
        return to_string(num);
    }
public:
    FileCacheManager() {}
    //load the data from file (if exist)
    bool loadData(string file_name) {
        ifstream file(file_name);
        S line, solution;
        if (file) {
            getline(file, line);
            if (line.compare("the solution is:") == 0) {
                getline(file, solution);
                mp.insert(pair<string, S>(file_name, solution));
            }
            file.close();
            return true;
        }
        return false;
    }
    //return bool type if the data exist in cache
    bool isExists(vector<P> problem) {
        return loadData(hashIt(problem));
    }
    //return the solution
    S getSolve(vector<P> problem) {
        string file_name = hashIt(problem);
        auto it = mp.find(file_name);
        return it->second;
    }
    //save the solution
    void save(vector<P> problem, S solution) {
        ofstream file(hashIt(problem));
        if (!file) {
            cerr << "can't save " << hashIt(problem) << endl;
            return;
        }
        file << "the solution is:" << "\n" << solution << "\n";
    }
};


#endif //EX4_FILECACHEMANAGER_H

