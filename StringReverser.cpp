#include "StringReverser.h"
string StringReverser::solve(string str1) {
    //reverse the original string
    int len = str1.length();
    int n = len - 1;
    for (int i = 0; i < (len / 2); i++) {
        //Using the swap method to switch values at each index
        swap(str1[i], str1[n]);
        n = n - 1;
    }
    return str1;
}