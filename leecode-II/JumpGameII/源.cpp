#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int step(0), maxstep(0);
        
        for (int i = 0; i <= maxstep; ++i)
        {
            ++step;
            if (maxstep + nums.at(maxstep) >= nums.size() - 1)
                return step;
            int tmp = maxstep;
            for (int c = tmp+1; c <= nums.at(tmp)+tmp; ++c)
            {
                if (nums.at(c) + c >= nums.size() - 1)
                    return step + 1;
                if (nums.at(c) + c > maxstep+nums.at(maxstep))
                    maxstep = c;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> test = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    cout << s.jump(test) << endl;
    system("pause");
    return 0;
}