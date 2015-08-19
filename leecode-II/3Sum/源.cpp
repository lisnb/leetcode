#include <algorithm>
#include <string>
#include <iostream>
#include <limits>
#include <vector>
#include <hash_set>
#include <functional>

using namespace std;


class Solution {
public:
    vector<vector<int>> twosum(vector<int> &nums, int target)
    {
        vector<vector<int>> re;
        if (nums.size() < 2)
            return re;
        int b(0), e(nums.size() - 1);
        while (b < e)
        {
            int t = nums[b] + nums[e];
            if (t == target)
                re.push_back({ nums[b++], nums[e--] });
            else if (t < target)
                ++b;
            else
                --e;
        }
        return re;
    }
    
    vector<vector<int>> twosum2(vector<int> &nums, int target)
    {
        vector<vector<int>> re;
        if (nums.size() < 2)
            return re;
        for (int i = 0; i + 1 < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                    re.push_back({ nums[i], nums[j] });
            }
        }
        return re;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        return threesum(nums, 0);

    }

    vector<vector<int>> threesum2(vector<int> &nums, int target)
    {
        vector<vector<int>> re;
        if (nums.size() < 3)
            return re;
        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            for (int j = i + 1; j + 1 < nums.size(); ++j)
            {
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (nums[i] + nums[j] + nums[k] == target)
                        re.push_back({ nums[i], nums[j], nums[k] });

                }
            }
        }
        return re;
    }

    vector<vector<int>> threesum(vector<int> &nums, int target)
    {
        if (nums.size() < 3)
            return{};
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        int size(nums.size() - 1);
        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            int b(i + 1), e(size), ttarget(target - nums[i]);
            while (b < e)
            {
                int tsum = nums[b] + nums[e];
                if (tsum == ttarget)
                {
                    re.push_back({ nums[i], nums[b], nums[e] });
                    while (b + 1 < e&&nums[b] == nums[b + 1])
                        ++b;
                    while (e - 1 > b&&nums[e] == nums[e - 1])
                        --e;
                    ++b;
                    --e;

                }
                else if (tsum > ttarget)
                    --e;
                else
                    ++b;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
        return re;

    }
   

    vector<vector<int>> threeSumAC(vector<int>& nums) {
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
    vector<int> test = { numeric_limits<int>::min() + 3, numeric_limits<int>::min() + 2, -2, 2, numeric_limits<int>::max()-1 };
    auto re = s.threesum2(test, 3);
    for (auto r : re)
        cout << r[0] << " " << r[1] << " "<<r[2]<< endl;
    /*cout << numeric_limits<int>::max() + 1 << endl;
    cout << numeric_limits<int>::min() - 1 << endl;
    cout << (numeric_limits<int>::min() - (2147483645)) << endl;*/
    auto a = hash<int>() ;
    system("pause");
    return 0;
}