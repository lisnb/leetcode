#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.at(0).empty())
            return;
        bool row(false), column(false);
        int m(matrix.size()), n(matrix.at(0).size());
        for (auto i = 0; i < m; ++i)
        {
            if (matrix.at(i).at(0) == 0)
            {
                column = true;
                break;
            }
        }
        for (auto i = 0; i < n; ++i)
        {
            if (matrix.at(0).at(i) == 0)
            {
                row = true;
                break;
            }
        }
        
        for (auto i = 1; i < m; ++i)
        {
            for (auto j = 1; j < n; ++j)
            {
                if (matrix.at(i).at(j) == 0)
                {
                    matrix.at(i).at(0) = 0;
                    matrix.at(0).at(j) = 0;
                }
            }
        }

        for (auto i = 1; i < m; ++i)
        {
            if (matrix.at(i).at(0) == 0)
            {
                for (auto j = 1; j < n; ++j)
                    matrix.at(i).at(j) = 0;
            }
        }
        for (auto i = 1; i < n; ++i)
        {
            if (matrix.at(0).at(i) == 0)
            {
                for (auto j = 1; j < m; ++j)
                    matrix.at(j).at(i) = 0;
            }
        }
        if (column)
            for (auto i = 0; i < m; ++i)
                matrix.at(i).at(0) = 0;
        if (row)
            for (auto i = 0; i < n; ++i)
                matrix.at(0).at(i) = 0;
    }
};



int main()
{
    Solution s;

    vector<vector<int>> grid = { { 0, 0, 0, 5 }, { 4, 3, 1, 4 }, { 0, 1, 1, 4 }, { 1, 2, 1, 3 }, {0, 0, 1, 1} };

    s.setZeroes(grid); 

    for (auto row : grid)
    {
        for (auto column : row)
            cout << column << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}