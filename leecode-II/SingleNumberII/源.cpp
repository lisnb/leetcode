#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones(0), twos(0), threes(0);
        for (auto num : nums)
        {
            twos |= ones&num;
            ones ^= num;
            threes = twos&ones;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};