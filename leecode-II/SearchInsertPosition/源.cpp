#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }

private:
    int search(const vector<int> &nums, int target, int b, int e)
    {
        if (nums.at(b) > target)
            return b;
        if (nums.at(e) < target)
            return e + 1;
        if (b == e)
        {
            if (nums.at(b) == target)
                return b;
            else
                return nums.at(b) > target ? b : b + 1;
        }
        int mid = b + (e - b) / 2;
        if (nums.at(mid) == target)
            return mid;
        else if (nums.at(mid) > target)
        {
            return search(nums, target, b, mid - 1);
        }
        else
            return search(nums, target, mid + 1, e);
    }

};


int main()
{
    Solution s;
    vector<int> nums = { 1, 3, 5, 6 };
    vector<int> test = { 5, 2, 7, 0 };
    for (auto t : test)
        cout << s.searchInsert(nums, t) << endl;
    system("pause");
    return 0;
}