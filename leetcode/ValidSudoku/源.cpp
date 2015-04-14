#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> blocks(9, 0);
        int t(0), cur(0);
        for (auto r = 0; r < 9; ++r)
        {
            for (auto c = 0; c < 9; ++c)
            {
                if (board.at(r).at(c) == '.')
                    continue;
                cur = board.at(r).at(c)-'0'-1;
                //row
                t = 1;
                t <<= r;
                if (rows.at(cur) & t)
                    return false;
                else
                    rows.at(cur) |= t;
                t = 1;
                t <<= c;
                if (cols.at(cur) & t)
                    return false;
                else
                    cols.at(cur) |= t;
                t = 1;
                t <<= (r / 3) * 3 + (c / 3);
                if (blocks.at(cur) & t)
                    return false;
                else
                    blocks.at(cur) |= t;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<unordered_set<int>> tests(10, unordered_set<int>());
    tests.at(0).insert(1);
    cout << (tests.at(2).find(1)==tests.at(2).end()) << endl;
    system("pause");
}