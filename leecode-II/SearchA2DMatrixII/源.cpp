#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.at(0).empty())
            return false;
        int r(0), c(matrix.at(0).size() - 1);
        while (r < matrix.size() && c >= 0)
        {
            if (matrix.at(r).at(c) == target)
                return true;
            else if (matrix.at(r).at(c) > target)
                --c;
            else
                ++r;
        }
        return false;
    }
    bool searchMatrixzTLE(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.at(0).empty())
            return false;
        return search(matrix, target, 0, 0, matrix.size() - 1, matrix.at(0).size() - 1);
    }

private:
    bool search(const vector<vector<int>> &matrix, int target, int bx, int by, int ex, int ey)
    {
        if (bx > ex || by > ey)
            return false;
        while (bx <= ex&&by <= ey)
        {
            int midx = bx + (ex - bx) / 2;
            int midy = by + (ey - by) / 2;
            if (matrix.at(midx).at(midy) == target)
                return true;
            else if (matrix.at(midx).at(midy) > target)
            {
                bool b1 = search(matrix, target, bx, by, midx - 1, ey);
                bool b2 = search(matrix, target, midx, by, ex, midy - 1);
                return b1 || b2;
            }
            else
            {
                bool b1 = search(matrix, target, bx, midy+1, ex, ey);
                bool b2 = search(matrix, target, midx + 1, by, ex, midy);
                return b1 || b2;
            }
        }
        return false;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    for (auto i = -1; i < 40; ++i)
        cout << i << " " << s.searchMatrix(matrix, i) << endl;
    cout << 15 << " " << s.searchMatrix(matrix, 15) << endl;
    system("pause");
    return 0;
}