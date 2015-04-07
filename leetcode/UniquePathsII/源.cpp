#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<int> level;
        bool ob = false;
        for (auto i : obstacleGrid.at(0))
        {
            if (i == 1)
                ob = true;
            level.push_back(ob ? 0 : 1);
        }
        if (level.front() == 0)
            return 0;
        for (auto i = 1; i < obstacleGrid.size(); ++i)
        {
            for (auto j = 0; j < obstacleGrid.at(i).size(); ++j)
            {
                if (obstacleGrid.at(i).at(j) == 1)
                {
                    level.at(j) = 0;
                    continue;
                }
                if (j >= 1 && obstacleGrid.at(i).at(j - 1) == 0)
                {
                    level.at(j) += level.at(j - 1);
                }
            }
        }

        return level.back();
    }
};


int main()
{
    Solution s;
    vector<vector<int>> test = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    cout << s.uniquePathsWithObstacles(test) << endl;
    system("pause");

}