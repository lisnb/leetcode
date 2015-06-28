#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canJumpWA(vector<int>& nums) {
        if (nums.empty())
            return false;
        for (int maxstep = nums.at(0); maxstep < nums.size()-1;)
        {
            if (nums.at(maxstep) == 0)
                return false;
            maxstep += nums.at(maxstep);
        }
        return true;
    }
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;
        int maxstep = 0;
        for (int i = 0; i <= maxstep; ++i)
        {
            if (nums.at(i) + i > maxstep)
            {
                maxstep = nums.at(i) + i;
                if (maxstep >= nums.size() - 1)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> test = {2, 5, 0, 0};
    cout << s.canJump(test) << endl;
    system("pause");
    return 0;

}