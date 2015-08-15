#include <unordered_set>
#include <vector>
#include <string>
#include <deque>
#include <iostream>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid.at(0).empty())
            return 0;
        int cnt = 0;
        int row(grid.size()), column(grid.at(0).size());
        unordered_set<int> cache;
        for (auto i = 0; i < grid.size(); ++i)
        {
            for (auto j = 0; j < grid.at(0).size(); ++j)
            {
                if (grid.at(i).at(j) == '1')
                {
                    ++cnt;
                    grid.at(i).at(j) = '.';
                    flip(grid, i, j, row, column);
                }
            }
        }
        return cnt;
    }


private:
    void addcell(vector<vector<char>> &grid, int r, int c, int row, int column, deque<pair<int, int>> &queue)
    {
        if (r < row && r >= 0 && c < column && c >= 0 && grid.at(r).at(c) == '1')
        {
            grid.at(r).at(c) = '.';
            queue.push_back(make_pair(r, c));
        }
    }

    void flip(vector<vector<char>> &grid, int r, int c, int row, int column)
    {
        deque<pair<int, int>> queue;
        queue.push_back(make_pair(r, c));
        pair<int, int> cur;
        while (!queue.empty())
        {
            cur = queue.front();
            queue.pop_front();
            r = cur.first;
            c = cur.second;
            addcell(grid, r + 1, c, row, column, queue);
            addcell(grid, r - 1, c, row, column, queue);
            addcell(grid, r, c + 1, row, column, queue);
            addcell(grid, r, c - 1, row, column, queue);
        }
    }


    void flip(vector<vector<char>> &grid, int r, int c, int row, int column, unordered_set<int> &cache)
    {
        deque<pair<int, int>> queue;
        queue.push_back({ r, c });
        int index(-1);
        while (!queue.empty())
        {
            auto cur = queue.front();
            queue.pop_front();
            grid.at(cur.first).at(cur.second) = '.';
            if (cur.first + 1 < row && grid.at(cur.first + 1).at(cur.second) == '1')
            {
                index = (cur.first + 1)*column + cur.second;
                if (cache.find(index) == cache.end())
                {
                    cache.insert(index);
                    queue.push_back({ cur.first + 1, cur.second });
                }
            }

            if (cur.first - 1 >= 0 && grid.at(cur.first - 1).at(cur.second) == '1')
            {
                index = (cur.first - 1)*column + cur.second;
                if (cache.find(index) == cache.end())
                {
                    cache.insert(index);
                    queue.push_back({ cur.first - 1, cur.second });
                }
            }

            if (cur.second + 1 < column && grid.at(cur.first ).at(cur.second + 1) == '1')
            {
                index = cur.first *column + cur.second + 1;
                if (cache.find(index) == cache.end())
                {
                    cache.insert(index);
                    queue.push_back({ cur.first , cur.second + 1 });
                }
            }

            if (cur.second - 1 >= 0 && grid.at(cur.first).at(cur.second - 1) == '1')
            {
                index = cur.first *column + cur.second - 1;
                if (cache.find(index) == cache.end())
                {
                    cache.insert(index);
                    queue.push_back({ cur.first, cur.second - 1 });
                }
            }
            
        }

    }
};


int main()
{
    Solution s;
    vector<vector<char>> test = {
        { '1', '1', '0', '0', '0' },
        { '1', '1', '0', '0', '0' },
        { '0', '0', '1', '0', '0' },
        { '0', '0', '0', '1', '1' }
    };
    vector<vector<char>> test2 = {
        { '1', '0', '1', '1', '1'},
        { '1', '0', '1', '0', '1' },
        { '1', '1', '1', '0', '1' },
    };
    vector<vector<char>> test3 = {
        { '1', '1', '1' },
        { '0', '1', '0' },
        { '1', '1', '1' }
    };
    cout << s.numIslands(test3) << endl;
    system("pause");
    return 0;
}