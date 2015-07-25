#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include "../leecode-II/leetcode.h"
using namespace std;



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), columns(9, 0), blocks(9, 0);
        for (auto i = 0; i < 9; ++i)
        {
            for (auto j = 0; j < 9; ++j)
            {
                if (board.at(i).at(j) == '.')
                    continue;
                int mask = 1 << (board.at(i).at(j) - '0' - 1);
                if ((rows.at(i) & mask) != 0)
                    return false;
                else
                    rows.at(i) |= mask;
                if ((columns.at(j)&mask) != 0)
                    return false;
                else
                    columns.at(j) |= mask;
                int blockindex = (i / 3) * 3 + (j / 3);
                if ((blocks.at(blockindex)&mask) != 0)
                    return false;
                else
                    blocks.at(blockindex) |= mask;
            }
        }
        return true;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 43 };
    auto root = lc_createlist<int>(test, false);
}