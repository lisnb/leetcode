#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int maxsum(numeric_limits<int>::min()), tsum(0);

        for (auto n : nums)
        {
            tsum += n;
            maxsum = max(maxsum, tsum);
            if (tsum < 0)
                tsum = 0;
        }
        return maxsum;
    }
};

int main()
{
    Solution s;
    vector<int> test = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    cout << s.maxSubArray(test) << endl;
    system("pause");
    return 0;
}