#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        return findmin(nums, 0, nums.size() - 1);
    }

private:

    int rotatemin(const vector<int> &nums)
    {
        int b(0), e(nums.size() - 1);
        while (b<e)
        {
            if (b == e)
                return nums.at(b);
            if (nums.at(b) < nums.at(e))
                return nums.at(b);
            int mid = b + ((e - b) >> 1);
            if (nums.at(mid) < nums.at(e))
                e = mid;
            else
                b = mid;
        }
        return nums.at(b);
    }

    int findmin(const vector<int> &nums, int b, int e)
    {
        if (b > e)
            return -1;
        if (b == e)
            return nums.at(b);
        if (nums.at(b) < nums.at(e))
            return nums.at(b);
        if (nums.at(b) == nums.at(e))
            return findmin(nums, b + 1, e);
        if (b + 1 == e)
            return nums.at(e);
        int mid = b + (e - b) / 2;
        if (nums.at(mid) < nums.at(mid - 1))
            return nums.at(mid);
        if (nums.at(mid) > nums.at(e))
            return findmin(nums, mid + 1, e);
        else if (nums.at(mid) < nums.at(e))
            return findmin(nums, b + 1, mid - 1);
        else
            return findmin(nums, b + 1, e - 1);

    }
};

int main()
{
    Solution s;
    vector<int> test = { 3, 1, 1 };
    cout << s.findMin(test) << endl;
    system("pause");
    return 0;
}