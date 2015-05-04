#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty() || t.size() > s.size() || (s.size() == t.size() && s != t))
            return 0;
        vector<vector<int>> index(t.size(), vector<int>(s.size(), 0));
        index.at(0).at(0) = s.at(0) == t.at(0) ? 1 : 0;
        for (auto i = 1; i < s.size(); ++i)
            index.at(0).at(i) = index.at(0).at(i - 1) + (t.at(0) == s.at(i) ? 1 : 0);
        for (auto i = 1; i < t.size(); ++i)
        {
            for (auto j = i; j < s.size(); ++j)
            {
                if (t.at(i) != s.at(j))
                    index.at(i).at(j) = index.at(i).at(j - 1);
                else
                {
                    index.at(i).at(j) = index.at(i).at(j - 1) + index.at(i - 1).at(j - 1);
                }
            }
        }
        return index.back().back();
    }
};