#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    int uniquePaths_ingrid(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> grid(m, vector<int>(n, 1));
        for (auto i = 1; i < m; ++i)
            for (auto j = 1; j < n; ++j)
                grid.at(i).at(j) = grid.at(i - 1).at(j) + grid.at(i).at(j - 1);
        return grid.back().back();
    }

    int uniquePaths(int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;
        vector<int> grid(n, 1);
        for (auto i = 1; i < m; ++i)
            for (auto j = 1; j < n; ++j)
                grid.at(j) += grid.at(j - 1);
        return grid.back();
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(5, 7) << endl;
    cout << s.uniquePaths_ingrid(5, 7) << endl;
    system("pause");
    return 0;
}