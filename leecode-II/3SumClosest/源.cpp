#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        long long closestsum(numeric_limits<int>::max()), tmp(0);
        for (auto i = 0; i < nums.size() - 2; ++i)
        {
            tmp = twoSumClosest(nums, i + 1, target, nums.at(i));
            if (abs(tmp - target) < abs(closestsum - target))
                closestsum = tmp;
        }
        return closestsum;
    }
private:

    long long twoSumClosest(vector<int> &nums, int begin, int target, int prefix)
    {
        size_t b(begin), e(nums.size() - 1);
        long long closestsum(numeric_limits<int>::max()), tmp(0);
        while (b < e)
        {
            tmp = nums.at(b) + nums.at(e) + prefix;
            if (tmp == target)
                return target;
            else if (tmp > target)
            {
                while (e - 1 > b && nums.at(e) == nums.at(e - 1))
                    --e;
                --e;
            }
            else
            {
                while (b + 1 < e && nums.at(b) == nums.at(b + 1))
                    ++b;
                ++b;
            }
            if (abs(closestsum - target) > abs(tmp - target))
                closestsum = tmp;
        }
        return closestsum ;
    }
};


int main()
{
    Solution s;
    vector<int> test = { -1, 2, 1, -4 , 7, -3};
    cout << s.threeSumClosest(test, 0) << endl;
    system("pause");
    return 0;
}