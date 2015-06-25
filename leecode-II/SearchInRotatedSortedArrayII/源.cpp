#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return searchindex(nums, target) != -1;
    }
public:
    int searchindex(vector<int>& nums, int target) {
        if (nums.empty() || (nums.size() == 1 && nums.at(0) != target))
            return -1;
        return binarysearch(nums, target, 0, nums.size() - 1);
    }

private:
    int binarysearch(const vector<int> &nums, int target, int b, int e)
    {
        if (b > e || (nums.at(b)>target && nums.at(e)<target))
            return -1;
        //if (b == e)
        //    return nums.at(b) == target ? b : -1;
        int mid = b + (e - b) / 2;
        if (nums.at(mid) == target)
            return mid;
        if (nums.at(b) >= nums.at(e))
        {
            int r1 = binarysearch(nums, target, b, mid - 1);
            int r2 = binarysearch(nums, target, mid + 1, e);
            return max(r1, r2);
        }
        else
            return nums.at(mid) > target ? binarysearch(nums, target, b, mid - 1) : binarysearch(nums, target, mid + 1, e);
    }
};

int main()
{
    Solution s;
    vector<int> test = { 3, 4, 5, 6, 7, 0, 1, 2, 3 };
    for (auto i = 0; i < 9; ++i)
        cout << i << " " << s.search(test, i) << endl;
    system("pause");
    return 0;
}
