#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> columns(n, -1);
        vector<vector<int>> re;
        nqueens(n, columns, re, 0);
        if (re.empty())
            return{};
        vector<vector<string>> grid;
        for (auto r : re)
        {
            vector<string> cgrid(n, string(n, '.'));
            for (int i = 0; i < r.size(); ++i)
                cgrid.at(i).at(r.at(i)) = 'Q';
            grid.push_back(cgrid);
        }
        return grid;
    }

private:

    void nqueens(int n, vector<int> &columns, vector<vector<int>> &re, int row)
    {
        if (row == n)
        {
            re.push_back(columns);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (isvalid(columns, row, i))
            {
                columns.at(row) = i;
                nqueens(n, columns, re, row + 1);
            }
        }
    }

    bool isvalid(vector<int> &columns, int row, int column)
    {
        for (int i = row - 1; i >= 0; --i)
        {
            int column2 = columns.at(i);
            if (column2 == column)
                return false;
            int horizontaldiff = abs(i - row);
            int verticaldiff = abs(column - column2);
            if (horizontaldiff == verticaldiff)
                return false;
        }
        return true;
    }
};


int main()
{
    Solution s;
    auto re = s.solveNQueens(4);
    for (auto r : re)
    {
        for (auto rr : r)
            cout << rr << endl;
        cout << endl;
    }
    system("pause");
    return 0;
}