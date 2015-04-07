#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;




class Solution {
public:

    int minPathSum(vector<vector<int>> &grid)
    {
        int sum = grid.at(0).at(0);
        //column
        for (auto i = 1; i < grid.size(); ++i)
        {
            sum += grid.at(i).at(0);
            grid.at(i).at(0) = sum;
        }
        sum = grid.at(0).at(0);
        for (auto i = 1; i < grid.at(0).size(); ++i)
        {
            sum += grid.at(0).at(i);
            grid.at(0).at(i) = sum;
        }
        sum = 0;
        for (auto i = 1; i < grid.size(); ++i)
            for (auto j = 1; j < grid.at(i).size(); ++j)
            {
                grid.at(i).at(j) = min(grid.at(i - 1).at(j), grid.at(i).at(j - 1))+grid.at(i).at(j);
            }
        return grid.back().back();
    }

    int minPathSumAC(vector<vector<int> > &grid) {
        int m = grid.size();
        if (m == 0)
            return -1;
        int n = grid.at(0).size();
        if (n == 0)
            return -1;
        cache.clear();
        int re = minpathsum(grid, 0, 0, m, n);

        for (auto i : cache)
            cout << i.first << " -> " << i.second << " ";
        cout << endl;
        return re;

    }

private:
    unordered_map<int, int> cache;
    int minpathsum(vector<vector<int>> &grid, vector<vector<int>>::size_type cm, vector<int>::size_type cn,
        vector<vector<int>>::size_type m, vector<int>::size_type n)
    {
        int index = cm*n + cn;
        if (cache.find(index) != cache.end())
            return cache[index];
        int pathsum = 0;
        if (cm == m - 1)
        {
            //bottom
            for (auto i = cn; i < n; ++i)
                pathsum += grid.at(cm).at(i);
        }
        else if (cn == n - 1)
        {
            //right
            for (auto i = cm; i < m; ++i)
                pathsum += grid.at(i).at(cn);
        }
        else
        {
            int rps = grid.at(cm).at(cn) + minpathsum(grid, cm, cn + 1, m, n);
            int dps = grid.at(cm).at(cn) + minpathsum(grid, cm + 1, cn, m, n);
            pathsum = rps<dps ? rps : dps;
        }
        
        cache[index] = pathsum;
        return pathsum;
    }
};


int main()
{
    Solution s;
    vector<vector<vector<int>>> tests = {
        {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
        },
        {
            {1},
            {2},
            {3},
            {4}
        },
        {
            {1,2,3},
            {4,5,6}
        }
    };

    for (auto t : tests)
    {
        cout << s.minPathSum(t) << endl;
    }

    system("pause");
}