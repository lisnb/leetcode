#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int rob(vector<int>& nums) {
        return rob2(nums);
    }

private:
    int rob1(vector<int> &nums)
    {
        vector<int> cache(nums.size(), -1);
        int mci = _rob1(nums, cache, 0, true);
        int mci2 = _rob1(nums, cache, 1, false);
        return max(mci, mci2);
    }

    int _rob1(vector<int> &nums, vector<int> &cache, int ci, bool first)
    {
        if (ci >= nums.size())
            return 0;
        int maxrob(0);
        
        if (ci + 1 == nums.size())
            return first ? 0 : nums.back();
        int mci = _rob1(nums, cache, ci + 2, first);
        int mci2 = _rob1(nums, cache, ci + 3, first);
        maxrob = max(nums.at(ci) + mci, nums.at(ci + 1) + mci2);
        return maxrob;
    }


    int rob2(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums.at(0);
        if (nums.empty())
            return 0;
        return max(_rob2(nums, 0, nums.size() - 1), _rob2(nums, 1, nums.size()));
    }

    int _rob2(vector<int> &nums, int ci, int ei)
    {
        int r_1(0), r_2(0);
        for (auto i = ci; i < ei; ++i)
        {
            int tmp = r_1;
            r_1 = max(r_2 + nums.at(i), r_1);
            r_2 = tmp;
        }
        return r_1;
    }
};

int main()
{
    Solution s;
    //vector<int> test = { 10, 2, 3, 20, 9, 1, 4 };
    vector<int> test = { 10};
    cout << s.rob(test) << endl;
    system("pause");
    return 0;
}