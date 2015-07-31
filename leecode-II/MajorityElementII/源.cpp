#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1(0), cur1(0), cnt2(0), cur2(0);
        for (auto num : nums)
        {
            if (num == cur1)
                ++cnt1;
            else if (num == cur2)
                ++cnt2;
            else if (cnt1 == 0)
            {
                cnt1 = 1;
                cur1 = num;
            }
            else if (cnt2 == 0)
            {
                cnt2 = 1;
                cur2 = num;
            }
            else
            {
                --cnt1;
                --cnt2;
            }
        }
        int cnt11(0), cnt22(0);
        for (auto num : nums)
        {
            if (num == cur1)
                ++cnt11;
            if (num == cur2)
                ++cnt22;
        }
        vector<int> re;
        if (cnt11 > nums.size() / 3)
            re.push_back(cur1);
        if (cnt22 > nums.size() / 3)
            re.push_back(cur2);
        return re;
    }


    int majorityElement2(vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        int cnt(0), cur(0);
        for (auto num : nums)
        {
            if (cnt == 0)
            {
                cur = num;
                cnt = 1;
                continue;
            }
            if (num == cur)
                ++cnt;
            else
                --cnt;
        }
        return cur;
    }
};



int main()
{
    Solution s;
    vector<int> test = { 2, 1, 3, 4, 2, 1, 2, 2 };
    cout << s.majorityElement2(test) << endl;
    system("pause");
    return 0;
}