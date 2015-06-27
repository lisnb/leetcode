#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (dict.find(nums.at(i)) == dict.end())
                dict.insert(make_pair(nums.at(i), i));
            else
            {
                if (i - dict.at(nums.at(i)) <= k)
                    return true;
                dict.at(nums.at(i)) = i;
            }
        }
        return false;
    }
};