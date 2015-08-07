#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty())
            return -1;
        vector<int> cache(256, 0);
        for (auto c : str)
            ++cache.at(c);
        for (int i = 0; i<str.size(); ++i)
        {
            if (cache.at(str.at(i)) == 1)
                return i;
        }
        return -1;
    }
};