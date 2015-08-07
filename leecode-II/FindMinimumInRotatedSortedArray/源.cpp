#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        return findmin(nums, 0, nums.size() - 1);
    }

    int rotatemin(const vector<int> &nums)
    {
        int b(0), e(nums.size() - 1);
        while (b<e)
        {
            if (b == e)
                return nums.at(b);
            if (nums.at(b) < nums.at(e))
                return nums.at(b);
            if (b + 1 == e)
                return nums.at(e);
            int mid = b + ((e - b) >> 1);
            if (nums.at(mid) < nums.at(mid - 1))
                return nums.at(mid);
            if (nums.at(mid) < nums.at(e))
                e = mid-1;
            else
                b = mid+1;
        }
        return nums.at(b);
    }

private:
    int findmin(const vector<int> &nums, int b, int e)
    {
        if (b > e)
            return -1;
        if (b == e)
            return nums.at(b);
        if (nums.at(b) < nums.at(e))
            return nums.at(b);
        if (b + 1 == e)
            return nums.at(e);
        int mid = b + (e - b) / 2;
        if (nums.at(mid) < nums.at(mid - 1))
            return nums.at(mid);
        else if (nums.at(mid) > nums.at(e))
            return findmin(nums, mid + 1, e);
        else
            return findmin(nums, b, mid - 1);

    }
};


int main()
{
    Solution s;
    vector<int> test = {3, 4, 5, 0, 1, 2};
    cout << s.findMin(test) << endl;
    cout << s.rotatemin(test) << endl;
    system("pause");
    return 0;
}