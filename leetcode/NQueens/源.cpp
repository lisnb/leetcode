#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        res.clear();
        vector<string> grid;
        string row(n, '.');
        for (auto i = 0; i < n; ++i)
            grid.push_back(row);
        nqueen(n, 0, grid);
        return res;

    }
private:
    vector<vector<string>> res;
    unordered_set<int> cols;
    bool hasqueen(int row, int col, vector<string> &grid, int n)
    {
        if (cols.find(col) != cols.end())
            return true;
        int lc(col - 1), rc(col + 1), r(row-1);
        while (lc<n && lc >= 0 && r>=0)
        {
            if (grid.at(r).at(lc) == 'Q')
                return true;
            --lc;
            --r;
        }
        r = row-1;
        while (rc>=0 && rc < n&&r >= 0)
        {
            if (grid.at(r).at(rc) == 'Q')
                return true;
            ++rc;
            --r;
        }
        return false;
    }
    void nqueen(int n, int index, vector<string> &grid)
    {
        if (index == n)
        {
            res.push_back(grid);
            return;
        }
        for (auto i = 0; i < n; ++i)
        {
            if (hasqueen(index, i, grid, n))
                continue;
            grid.at(index).at(i) = 'Q';
            cols.insert(i);
            nqueen(n, index + 1, grid);
            cols.erase(i);
            grid.at(index).at(i) = '.';
        }
    }
};



int main()
{
    Solution s;
    vector<int> tests = { 4, 5, 6, 7, 8, 9};
    for (auto test : tests)
    {
        auto re = s.solveNQueens(test);
        cout << test <<" "<< re.size()<<endl;
        /*for (auto rer : re)
        {
            
            for (auto rere : rer)
            {
                cout << rere << endl;
            }
            cout << endl << endl;
        }*/
    }
    system("pause");

}