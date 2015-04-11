#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int index(0);
        int cnt(0);
        int m(grid.size());
        if (m == 0)
            return 0;
        cache.clear();
        int n(grid.at(0).size());
        for (auto i = 0; i < grid.size(); ++i)
        {
            for (auto j = 0; j < grid.at(i).size(); ++j)
            {
                index = i*n + j;
                if (cache.find(index) == cache.end() && grid.at(i).at(j) == '1')
                {
                    dfs(grid, m, n, i, j, '2');
                    ++cnt;
                }
            }
        }

        return cnt;
    }

private:
    unordered_set<int> cache;

    void dfs(vector<vector<char>> &grid, int m, int n, int cm, int cn, char flag)
    {
        int index(cm*n + cn);
        cache.insert(index);
        if (grid.at(cm).at(cn) == '0')
            return;
        grid.at(cm).at(cn) = flag;
        if (cm + 1 < m  && cache.find((cm + 1)*n + cn) == cache.end())
        {
            dfs(grid, m, n, cm+1, cn, flag);
        }
        if (cm - 1 >=0  && cache.find((cm - 1)*n + cn) == cache.end())
        {
            dfs(grid, m, n, cm - 1, cn, flag);
        }
        if (cn + 1 < n && cache.find(cm*n + cn + 1) == cache.end())
        {
            dfs(grid, m, n, cm, cn + 1, flag);
        }
        if (cn - 1 >= 0 && cache.find(cm*n + cn - 1) == cache.end())
        {
            dfs(grid, m, n, cm, cn - 1, flag);
        }
    }
};



int main()
{
    Solution s;
    vector<vector<vector<char>>> tests = {
        {
            { '1', '1', '1', '1', '0' },
            { '1', '1', '0', '1', '0' },
            { '1', '1', '0', '0', '0' },
            { '0', '0', '0', '0', '0' },
        },
        {
            { '1', '1', '0', '0', '0' },
            { '1', '1', '0', '0', '0' },
            { '0', '0', '1', '0', '0' },
            { '0', '0', '0', '1', '1' },
        }
    };

    for (auto t : tests){
        cout << s.numIslands(t) << endl;
    }
    system("pause");
}