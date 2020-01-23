#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <string>
#include <vector>

using namespace std;
template<class P,class S>
class CacheManager {
public:
    virtual bool isExists(vector<P> problem) = 0;

    virtual S getSolve(vector<P> problem) = 0;

    virtual void save(vector<P> problem,S solution) = 0;

    virtual ~CacheManager() {}
};

#endif