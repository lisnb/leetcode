#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> blocks(9, vector<bool>(9, false));
        if (!initialboard(board, rows, cols, blocks))
            return;

        solve(0, board, rows, cols, blocks);
    }

private:

    bool initialboard(vector<vector<char>> &board, vector<vector<bool>> &rows, vector<vector<bool>> &cols, vector<vector<bool>> &blocks)
    {
        int cur(0), t(0);
        for (auto r = 0; r < 9; ++r)
        {
            for (auto c = 0; c < 9; ++c)
            {
                if (board.at(r).at(c) == '.')
                    continue;
                cur = board.at(r).at(c) - '0' - 1;
                if (rows.at(r).at(cur))
                    return false;
                else
                    rows.at(r).at(cur) = true;
                
                if (cols.at(c).at(cur))
                    return false;
                else
                    cols.at(c).at(cur) = true;
                t = (r / 3) * 3 + (c / 3);
                if (blocks.at(t).at(cur))
                    return false;
                else
                    blocks.at(t).at(cur) = true;
            }
        }
        return true;
    }

    bool solve(int index, vector<vector<char>> &board, vector<vector<bool>> &rows, vector<vector<bool>> &cols, vector<vector<bool>> &blocks)
    {
        if (index >80)
            return true;
        int row(index / 9 );
        int col(index - row * 9);
        if (board.at(row).at(col) != '.')
            return solve(index + 1, board, rows, cols, blocks);
        bool res(false);
        for (int i = 0; i < 9; ++i)
        {
            if (isvalid(row, col, i, rows, cols, blocks))
            {
                board.at(row).at(col) = '0' + i + 1;
                set(row, col, i, rows, cols, blocks);
                res = solve(index + 1, board, rows, cols, blocks);
                if (res)
                    return res;
                else
                {
                    reset(row, col, i, rows, cols, blocks);
                    board.at(row).at(col) = '.';
                }
            }
        }
        return false;
    }

    bool isvalid(int row, int col, int num, vector<vector<bool>> &rows, vector<vector<bool>> &cols, vector<vector<bool>> &blocks)
    {
        int t((row / 3) * 3 + (col / 3));
        return !(rows.at(row).at(num) || cols.at(col).at(num) || blocks.at(t).at(num));
    }

    void set(int row, int col, int num, vector<vector<bool>> &rows, vector<vector<bool>> &cols, vector<vector<bool>> &blocks)
    {
        rows.at(row).at(num) = true;
        cols.at(col).at(num) = true;
        blocks.at((row / 3) * 3 + (col / 3)).at(num) = true;
    }

    void reset(int row, int col, int num, vector<vector<bool>> &rows, vector<vector<bool>> &cols, vector<vector<bool>> &blocks)
    {
        rows.at(row).at(num) = false;
        cols.at(col).at(num) = false;
        blocks.at((row / 3) * 3 + (col / 3)).at(num) = false;
    }
};



int main()
{
    Solution s;

    vector<bool> b1;
    b1.push_back(true);
    b1.push_back(false);

    vector<vector<char>> test = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '.' }
    };
    vector<vector<char>> test2 = {
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' }
    };

    s.solveSudoku(test2);

    for (auto rer : test2)
    {
        for (auto rere : rer)
        {
            cout << rere << " ";
        }
        cout << endl;
    }
    system("pause");
}