#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty() || board.empty() || board.at(0).empty())
            return false;
        bool re(false);
        int m(board.size()), n(board.at(0).size());
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                re = exist(board, i, j, word, 0, m, n);
                if (re)
                    return re;
            }
        }
    }
private:
    bool exist(vector<vector<char>> &board, int cr, int cl, const string &word, int ci, int m, int n)
    {
        if (ci == word.size())
            return true;
        if (cr < 0 || cr >= m || cl < 0 || cl >= n || board.at(cr).at(cl) != word.at(ci))
            return false;
        auto track = board.at(cr).at(cl);
        board.at(cr).at(cl) = '.';
        auto tmpcrp1 = exist(board, cr + 1, cl, word, ci + 1, m, n);
        if (tmpcrp1)
        {
            board.at(cr).at(cl) = track;
            return true;
        }
        auto tmpcrm1 = exist(board, cr - 1, cl, word, ci + 1, m, n);
        if (tmpcrm1)
        {
            board.at(cr).at(cl) = track;
            return true;
        }
        auto tmpclp1 = exist(board, cr, cl + 1, word, ci + 1, m, n);
        if (tmpclp1)
        {
            board.at(cr).at(cl) = track;
            return true;
        }
        auto tmpclm1 = exist(board, cr, cl - 1, word, ci + 1, m, n);
        if (tmpclm1)
        {
            board.at(cr).at(cl) = track;
            return true;
        }
        board.at(cr).at(cl) = track;
        return false;
    }
};


int main()
{
    Solution s;
    vector<vector<char>> board = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' },
        { 'A', 'D', 'E', 'E' }
    };
    vector<vector<char>> board2 = {
        { 'a' }
    };
    vector<string> test = { "ab", "ABCB", "ABCCED", "SEE", "ABCB" };
    for (auto t : test)
        cout << t << " " << s.exist(board2, t) << endl;
    system("pause");
    return 0;
}