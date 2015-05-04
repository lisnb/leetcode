#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



class Solution {
public:
    int myAtoi(string str) {
        int b(0);
        int e(str.size() - 1);
        while (b < str.size() && str.at(b) == ' ')
            ++b;
        while (e >= b&&str.at(e) == ' ')
            --e;
        if (e < b)
            return 0;

    }
};