#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid.at(0).empty())
            return 0;
        if (obstacleGrid.at(0).at(0) == 1)
            return 0;
        int m(obstacleGrid.size()), n(obstacleGrid.at(0).size());
        obstacleGrid.at(0).at(0) = 1;
        for (auto i = 1; i < n; ++i)
            obstacleGrid.at(0).at(i) = obstacleGrid.at(0).at(i) == 1 ? 0 : obstacleGrid.at(0).at(i - 1);
        for (auto i = 1; i < m; ++i)
            obstacleGrid.at(i).at(0) = obstacleGrid.at(i).at(0) == 1 ? 0 : obstacleGrid.at(i - 1).at(0);

        for (auto i = 1; i < m; ++i)
            for (auto j = 1; j < n; ++j)
            {
                if (obstacleGrid.at(i).at(j) == 1)
                    obstacleGrid.at(i).at(j) = 0;
                else
                    obstacleGrid.at(i).at(j) = obstacleGrid.at(i - 1).at(j) + obstacleGrid.at(i).at(j - 1);
            }
        return obstacleGrid.back().back();
    }
};