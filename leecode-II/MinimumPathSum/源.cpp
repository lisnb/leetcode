#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid.at(0).empty())
            return 0;
        int m(grid.size()), n(grid.at(0).size());
        for (auto i = 1; i < m; ++i)
            grid.at(i).at(0) += grid.at(i - 1).at(0);
        for (auto i = 1; i < n; ++i)
            grid.at(0).at(i) += grid.at(0).at(i - 1);

        for (auto i = 1; i < m; ++i)
        {
            for (auto j = 1; j < n; ++j)
            {
                grid.at(i).at(j) += min(grid.at(i - 1).at(j), grid.at(i).at(j - 1));
            }
        }
        return grid.back().back();
    }
};
