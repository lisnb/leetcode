#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int>> opt(s1.size() + 1, vector<int>(s2.size(), 0));
        opt[0][0] = 1;
        for (auto i = 0; i < s1.size(); ++i)
            opt[i + 1][0] = (opt[i][0] == 1 && s1[i] == s3[i]) ? 1 : 0;
        for (auto j = 0; j < s2.size(); ++j)
            opt[0][j + 1] = (opt[0][j] == 1 && s2[j] == s3[j]) ? 1 : 0;
        for (auto i = 0; i < s1.size(); ++i)
        {
            for (auto j = 0; j < s2.size(); ++j)
            {
                if (opt[i][j + 1] == 1)
                    opt[i + 1][j + 1] = s1[i] == s3[i + j + 1] ? 1 : 0;
                if (opt[i + 1][j] == 1)
                    opt[i + 1][j + 1] = s2[j] == s3[i + j + 1] ? 1 : 0;
            }
        }
        return opt.back().back() == 1;
    }
};