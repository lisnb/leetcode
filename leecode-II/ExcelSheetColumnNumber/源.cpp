#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


/*
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*/

class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty())
            return 0;
        int n = 0;
        for (auto c : s)
        {
            n = 26 * n + c - 'A' + 1;
        }
        return n;
    }
};