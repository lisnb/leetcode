#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    /*
        The brute force approach is simple. Loop through each element x and find if
        there is another value that equals to target-x. As finding another value 
        requires looping through the rest of array, its runtime complexity is O(n^2)

        We could reduce the runtime complexity of looking up a value to O(1) using 
        a hashmap that maps a value to its index.
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (dict.find(target - nums.at(i)) != dict.end())
            {
                return{ dict.at(target - nums.at(i))+1, i+1 };
            }
            dict.insert(make_pair(nums.at(i), i));
        }
        return{};
    }
    /*
        Of course we could still apply the hash table approach, but it
        costs us O(n) extra space, plus, it does not make use of the fact 
        that the input is already sorted.

        For each element x, we could look up if target-x exists in O(logn) 
        time by applying binary search over the sorted array. Total runtime 
        complexity is O(nlogn).
    */
    vector<int> twoSumII(vector<int> &nums, int target)
    {
        for (auto i = 0; i + 1 < nums.size(); ++i)
        {
            int tindex = bsearch(nums, target - nums.at(i), i + 1);
            if (tindex != -1)
                return{ i + 1, tindex + 1 };
        }
        return{};
    }

    int bsearch(const vector<int> &nums, int target, int s)
    {
        int b(s), e(nums.size() - 1);
        while (b <= e)
        {
            int mid = b + ((e - b) >> 1);
            if (nums.at(mid) == target)
                return mid;
            else if (nums.at(mid) > target)
                e = mid - 1;
            else
                b = mid + 1;
        }
        return -1;
    }

    /*
        Let's assume we have two indices (['ɪndɪsiz]) pointing to the ith and jth
        elements, Ai and Aj repectively. The sum of Ai and Aj could only fall into 
        one of there three possibilities:
            i.   Ai + Aj > target. Increasing i isn't going to help us, as it makes 
                 the sum even bigger. Therefore we should decrease j.
            ii.  Ai + Aj < target. Decreasing j isn't going to help us, as it makes 
                 the sum even smaller. Therefore we should increase i instead.
            iii. Ai + Aj == target. We have found the anwser.
    */
    vector<int> twoSumIII(vector<int> &nums, int target)
    {
        int i(0), j(nums.size() - 1);
        while (i < j)
        {
            int tsum = nums.at(i) + nums.at(j);
            if (tsum == target)
                return{ i + 1, j + 1 };
            else if (tsum > target)
                --j;
            else
                ++i;
        }
        return{};
    }
};