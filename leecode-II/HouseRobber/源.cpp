#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;




class Solution {
public:
    int rob(vector<int>& nums) {
        //return rob1(nums);
        return rob2(nums);
    }

private:
    int rob1(vector<int> &nums)
    {
        vector<int> cache(nums.size(), -1);
        return _rob1(nums, 0, cache);
    }
    int _rob1(vector<int> &nums, int ci, vector<int> &cache)
    {
        if (ci >= nums.size())
            return 0;
        if (cache.at(ci) != -1)
            return cache.at(ci);
        int maxrob = ci + 1 == nums.size() ? nums.at(ci) : max(nums.at(ci) + _rob1(nums, ci + 2, cache), nums.at(ci + 1) + _rob1(nums, ci + 3, cache));
        cache.at(ci) = maxrob;
        return maxrob;
    }


    int rob2(vector<int> &nums)
    {
        int c_1(0), c_2(0);
        for (auto n : nums)
        {
            int tmp = c_1;
            c_1 = max(c_1, c_2 + n);
            c_2 = tmp;
        }
        return c_1;
    }

};


int main()
{
    Solution s;
    vector<int> test = { 1, 2};
    cout << s.rob(test) << endl;
    system("pause");
    return 0;
}