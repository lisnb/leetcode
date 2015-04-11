#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution {
public:
    void solve(vector<vector<char>> &board) {
        auto m = board.size();
        if (m <= 2)
            return;
        auto n = board.at(0).size();
        if (n <= 2)
            return;
        for (auto i = 0; i < m; ++i)
        {
            if (board.at(i).at(0) == 'O')
                solve(board, m, n, i, 0);
            if (board.at(i).at(n-1) == 'O')
                solve(board, m, n, i, n - 1);
        }
        for (auto j = 1; j < n - 1; ++j)
        {
            if (board.at(0).at(j) == 'O')
                solve(board, m, n, 0, j);
            if (board.at(m-1).at(j) == 'O')
                solve(board, m, n, m - 1, j);
        }
        for (auto i = 0; i < m; ++i)
            for (auto j = 0; j < n; ++j)
            {
                if (board.at(i).at(j) == '@')
                    board.at(i).at(j) = 'O';
                else if (board.at(i).at(j) == 'O')
                    board.at(i).at(j) = '#';
            }
    }

private:
    unordered_set<int> cache;

    void solve(vector<vector<char>> &board, int m, int n, int cm, int cn)
    {
        queue<pair<int, int>> q;
        q.push({ cm, cn });
        int index(-1);
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            board.at(cur.first).at(cur.second) = '@';
            if (cur.first + 1 < m&&board.at(cur.first + 1).at(cur.second) == 'O'){
                index = (cur.first + 1)*n + cur.second;
                if (cache.find(index) == cache.end())
                {
                    cache.insert(index);
                    q.push({ cur.first + 1, cur.second });
                }
            }
                
            if (cur.first - 1 >= 0 && board.at(cur.first - 1).at(cur.second) == 'O'){
                index = (cur.first - 1)*n + cur.second;
                if (cache.find(index) == cache.end())
                {
                    cache.insert(index);
                    q.push({ cur.first - 1, cur.second });
                }
            }
                
            if (cur.second + 1 < n&&board.at(cur.first).at(cur.second + 1) == 'O'){
                index = cur.first*n + cur.second + 1;
                if (cache.find(index) == cache.end())
                {
                    cache.insert(index);
                    q.push({ cur.first, cur.second + 1 });
                }
            }
            
            if (cur.second - 1 >= 0 && board.at(cur.first).at(cur.second - 1) == 'O'){
                index = cur.first *n + cur.second - 1;
                if (cache.find(index) == cache.end())
                {
                    cache.insert(index);
                    q.push({ cur.first, cur.second - 1 });
                }
            }
                
        }

    }
    
    void solveRTE(vector<vector<char>> &board, int m, int n, int cm, int cn)
    {
        

        /*if (board.at(cm).at(cn) == 'O')
        {*/
            board.at(cm).at(cn) = '@';
            if (cm + 1 < m && board.at(cm + 1).at(cn) == 'O')
                solve(board, m, n, cm + 1, cn);
            if (cm - 1 >= 0 && board.at(cm - 1).at(cn) == 'O')
                solve(board, m, n, cm - 1, cn);
            if (cn + 1 < n&& board.at(cm).at(cn +1 ) == 'O')
                solve(board, m, n, cm, cn + 1);
            if (cn - 1 >= 0 && board.at(cm).at(cn-1) == 'O')
                solve(board, m, n, cm, cn - 1);
        //}
    }

};


int main()
{
    Solution s;
    vector<vector<char>> test = {
        { '#', '#', '#', '#'},
        { '#', 'O', 'O', '#' },
        { '#', '#', 'O', '#' },
        { '#', 'O', '#', '#' }
    };
    /*vector<vector<char>> test = {
        { '#', '#', '#' },
        { '#', 'O', '#' },
        { '#', '#', '#' }
    };
*/
    /*vector<vector<char>> test = {
        { 'O', 'O', 'O' },
        { 'O', 'O', 'O' },
        { 'O', 'O', 'O' }
    };*/
    s.solve(test);
    system("pause");
}