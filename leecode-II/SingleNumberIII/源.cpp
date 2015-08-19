#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() <= 1)
            return{};
        int xorre(0);
        for (auto &num : nums)
            xorre ^= num;
        if (xorre == 0)
            return{};

        int mask = getmask(xorre);
        int first(0), second(0);
        for (auto num : nums)
        {
            if ((num&mask) == 0)
                first ^= num;
            else
                second ^= num;
        }
        return{ first, second };
    }

private:
    int getmask(int xorre)
    {
        int mask = 0x1;
        while ((mask&xorre) == 0)
            mask <<= 1;
        return mask;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 0, 0, 1, 2 };
    auto re = s.singleNumber(test);
    system("pause");
    return 0;
}