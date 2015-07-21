#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> cache;
        for (auto num : nums)
            cache.insert(make_pair(num, 0));
        int longestc = 0;
        for (auto num : nums)
        {
            if (cache[num] == 0)
            {
                int tlong = longest(cache, num);
                longestc = max(longestc, tlong);
            }
        }
        return longestc;
    }
private:
    int longest(unordered_map<int, int> &cache, int num)
    {
        if (cache.find(num) == cache.end() || cache[num] != 0)
            return 0;
        cache[num] = 1;
        return 1 + longest(cache, num - 1) + longest(cache, num + 1);
    }

public:
    int longestConsecutive2(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        radixsort(nums);

        int longest(0);
        int current(nums.at(0));
        int cnt(1);
        for (auto i = 1; i < nums.size(); ++i)
        {
            if (nums.at(i) == current + 1)
                ++cnt;
            else
            {
                longest = max(longest, cnt);
                cnt = 1;
            }
            current = nums.at(i);
        }   
        return longest;

    }

    void radixsort(vector<int> &nums)
    {
        long long ex = 1;
        int maxnum = *max_element(nums.begin(), nums.end());
        vector<int> bucket(10, 0);
        vector<int> nums2(nums);
        bool reversed = false;
        while (maxnum / ex > 0)
        {
            bucket.assign(10, 0);
            for (auto num : nums)
                ++bucket[(num / ex) % 10];
            for (auto i = 1; i < bucket.size(); ++i)
                bucket[i] += bucket[i - 1];
            if (reversed)
                for (int i = nums2.size() - 1; i >= 0;--i)
                    nums[--bucket[(nums2.at(i) / ex) % 10]] = nums2.at(i);
            else
                for (int i = nums.size() - 1; i >= 0; --i)
                    nums2[--bucket[(nums.at(i) / ex) % 10]] = nums.at(i);
            reversed = !reversed;
            ex *= 10;
        }
        if (reversed)
            swap(nums, nums2);
    }

};

int main()
{
    Solution s;
    //vector<int> test = {18, 15, 23, 48, 171, 354, 287, 1908 };
    vector<int> test = { 2147483646, -2147483647, 0, 2, 2147483644, -2147483645, 2147483645 };
    cout << s.longestConsecutive2(test) << endl;
    /*s.radixsort(test);
    for (auto num : test)
        cout << num << endl;*/
    system("pause");
    return 0;
}