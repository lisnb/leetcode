#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle.at(0).empty())
            return 0;
        if (triangle.size() == 1)
            return triangle.front().front();
        for (int level = triangle.size() - 2; level >= 0; --level)
        {
            for (int i = 0; i < triangle.at(level).size(); ++i)
            {
                triangle.at(level).at(i) += min(triangle.at(level + 1).at(i), triangle.at(level + 1).at(i + 1));
            }
        }
        return triangle.front.front();
    }
};

