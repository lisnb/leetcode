#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.at(0).empty())
            return false;
        if (matrix.at(0).at(0) > target||matrix.back().back()<target)
            return false;
        vector<int> firstcolumn(matrix.size(), 0);
        for (auto i = 0; i < firstcolumn.size(); ++i)
            firstcolumn.at(i) = matrix.at(i).at(0);
        auto i1 = search4(firstcolumn, target);
        if (i1 < firstcolumn.size() && firstcolumn.at(i1) == target)
            return true;
        --i1;
        auto i2 = search4(matrix.at(i1), target);
        if (i2 == matrix.at(i1).size())
            return false;
        return matrix.at(i1).at(i2) == target;
    }
private:
    int search4(const vector<int> &nums, int target)
    {
        int b(0), e(nums.size() - 1), mid(0);
        while (b <= e)
        {
            if (target < nums.at(b))
                return b;
            if (target>nums.at(e))
                return e + 1;
            mid = b + ((e - b) >> 1);
            if (nums.at(mid) == target)
                return mid;
            else if (nums.at(mid) > target)
                e = mid - 1;
            else
                b = mid + 1;
        }
    }
};



int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        { 1, 3, 5, 7 },
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    for (auto i = 0; i < 55; ++i)
        cout << i << " " << s.searchMatrix(matrix, i) << endl;
    system("pause");
    return 0;
}