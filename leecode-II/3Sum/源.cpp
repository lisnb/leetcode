#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> re;
        if (nums.size() < 3)
            return re;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size() - 2; ++i)
        {
            twoSum(re, nums, i + 1, nums.at(i), 0 - nums.at(i));
            while (i + 1 < nums.size() && nums.at(i) == nums.at(i + 1))
                ++i;
        }
        return re;
    }

private:
    void twoSum(vector<vector<int>> &re, const vector<int> &nums, int begin, int prefix, int target)
    {
        

        size_t b(begin), e(nums.size() - 1);
        int tmp(0);
        while (b < e)
        {
            tmp = nums.at(b) + nums.at(e);
            if (tmp == target)
            {
                re.push_back({ prefix, nums.at(b), nums.at(e) });
                while (b + 1 < e && nums.at(b) == nums.at(b + 1))
                    ++b;
                while (e - 1 > b && nums.at(e) == nums.at(e - 1))
                    --e;
                ++b;
                --e;
            }
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
        }
    }
};



int main()
{
    Solution s;
    vector<int> test = { -1, 0, 1, 2, -1, -4 , 7, -4, -3};
    auto re = s.threeSum(test);
    for (auto r : re)
        cout << r[0] << " " << r[1] << " " << r[2] << endl;
    system("pause");
    return 0;
}