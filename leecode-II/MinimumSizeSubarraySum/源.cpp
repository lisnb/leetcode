#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int p1(-1), p2(0), minlen(nums.size()), tmpsum(0);
        while (p2 < nums.size())
        {
            while (p2 < nums.size() && tmpsum < s)
                tmpsum += nums.at(p2++);
            //if (p2 == nums.size())
                //break;
            while (p1 < p2&&tmpsum >= s)
                tmpsum -= nums.at(++p1);
            minlen = min(minlen, p2 - p1);
            if (minlen == 1)
                return 1;
        }
        return minlen == nums.size() ? 0 : minlen;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 2, 3};
    cout << s.minSubArrayLen(7, test) << endl;
    system("pause");
    return 0;
}