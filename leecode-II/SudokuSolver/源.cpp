#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
    typedef vector<int> array;
public:
    void solveSudoku(vector<vector<char>>& board) {
        array rows(9, 0), columns(9, 0), blocks(9, 0);
        for (auto i = 0; i < 9; ++i)
        {
            for (auto j = 0; j < 9; ++j)
            {
                if (board.at(i).at(j) == '.')
                    continue;
                int mask = 1 << (board.at(i).at(j) - '0' - 1);
                rows.at(i) |= mask;
                columns.at(j) |= mask;
                int blockindex = (i / 3) * 3 + (j / 3);
                blocks.at(blockindex) |= mask;
            }
        }

        solve(board, rows, columns, blocks, 0);
    }

private:
    bool solve(vector<vector<char>> &board, array &rows, array &columns, array &blocks, int index)
    {
        int r, c;
        for (; index < 81; ++index)
        {
            r = (index / 9);
            c = (index - r * 9);
            if (board.at(r).at(c) == '.')
                break;
        }
        if (index == 81)
            return true;
        for (auto i = 1; i <= 9; ++i)
        {
            int mask = 1 << (i - 1);
            if (isvalid(rows, columns, blocks, r, c, mask))
            {
                
                board.at(r).at(c) = '0' + i;
                setit(rows, columns, blocks, r, c, mask);
                bool re = solve(board, rows, columns, blocks, index + 1);
                if (re)
                    return re;
                else
                {
                    unsetit(rows, columns, blocks, r, c, mask);
                    board.at(r).at(c) = '.';
                }
            }
        }
        return false;
    }

    bool isvalid(array &row, array &columns, array &blocks, int r, int c, int mask)
    {
        return ((mask & row.at(r)) == 0) && ((mask & columns.at(c)) == 0) && ((blocks.at(r / 3 * 3 + c / 3)&mask) == 0);
    }

    void setit(array &rows, array &columns, array &blocks, int r, int c, int mask)
    {
        rows.at(r) |= mask;
        columns.at(c) |= mask;
        blocks.at(r / 3 * 3 + c / 3) |= mask;
    }

    void unsetit(array &rows, array &columns, array &blocks, int r, int c, int mask)
    {
        mask = ~mask;
        rows.at(r) &= mask;
        columns.at(c) &= mask;
        blocks.at(r / 3 * 3 + c / 3) &= mask;
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

    vector<vector<char>> test3 = {
        { '5', '3', '4', '6', '7', '8', '9', '1', '2' },
        { '6', '7', '2', '1', '9', '5', '3', '4', '8' },
        { '1', '9', '8', '3', '4', '2', '5', '6', '7' },
        { '8', '5', '9', '7', '6', '1', '4', '2', '3' },
        { '4', '2', '6', '8', '5', '3', '7', '9', '1' },
        { '7', '1', '3', '9', '2', '4', '8', '5', '6' },
        { '9', '6', '1', '5', '3', '7', '2', '8', '4' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '.' }
    };

    s.solveSudoku(test);

    for (auto rer : test)
    {
        for (auto rere : rer)
        {
            cout << rere << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}