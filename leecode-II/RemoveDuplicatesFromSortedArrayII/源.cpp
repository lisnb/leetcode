#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return removedup(nums, 0, nums.size(), 2);
    }


private:
    int removedup(vector<int> &nums, int s, int e, int count)
    {
        int cur = nums.at(s), cnt=1, p1(s), p2(s+1);
        while (p2 < e)
        {
            if (nums.at(p2) == cur)
                ++cnt;
            else
            {
                cur = nums.at(p2);
                cnt = 1;
            }
            if (cnt <= count)
                nums.at(++p1) = nums.at(p2);
            ++p2;
        }
        return p1;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1, 1, 1, 2, 2, 3 };
    auto t = s.removeDuplicates(test);
    return 0;

}