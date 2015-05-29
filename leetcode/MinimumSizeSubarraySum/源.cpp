#include <algorithm>
#include <iostream>
#include <vector>



using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        size_t p1(0), p2(0);
        int sum = 0;
        size_t mingap(nums.size()+1);
        while (p2 < nums.size())
        {
            sum += nums.at(p2);
            if (nums.at(p2) >= s)
                return 1;
            while (p1 <= p2 && sum >= s)
            {
                mingap = min(mingap, p2 - p1 + 1);
                sum -= nums.at(p1);
                ++p1;
            }
           
            ++p2;
        }
        return mingap==nums.size()+1?0:mingap;
    }

    int minSubArray(int s, vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        vector<int> sums = {nums.at(0)};
        for (auto i = 1; i<nums.size(); ++i)
            sums.push_back(nums.at(i) + sums.at(i - 1));
        int mingap = nums.size() + 1;
        int e = nums.size() - 1;
        for (auto i = 0; i < nums.size();++i)
        {
            if (nums.at(i) >= s)
                return 1;
            int tmingap = binarysearch(s - nums.at(i)+sums.at(i), sums, i + 1, e);
            if (tmingap == -1 )
                continue;
            mingap = min(mingap, tmingap-i+1);
        }
        return mingap == nums.size() + 1 ? 0 : mingap;
    }

    int binarysearch(int s, vector<int> &nums, int b, int e)
    {
        if (b > e)
            return -1;
        if (b == e)
        {
            if (nums.at(b) >= s)
                return b;
            else
                return -1;
        }
        int mid(b + (e - b) / 2);
        if (nums.at(mid) == s)
            return mid;
        else if (nums.at(mid) > s)
        {
            int lr = binarysearch(s, nums, b, mid - 1);
            if (lr == -1)
                return mid;
            return min(mid, lr);
        }
        else
        {
            int rr = binarysearch(s, nums, mid + 1, e);
            return rr;
        }
        
    }
};


int main()
{
    Solution s;
    vector<int> test = { 2, 3, 1, 2, 4, 3, 4,3 };
    cout <<14 << "\t" << s.minSubArray(14, test) << "\t" << s.minSubArrayLen(14, test) << endl;
    //cout << s.minSubArrayLen(100, test) << endl;
    for (auto i = 0; i < 27; ++i)
    {
        cout <<i<<"\t"<<s.minSubArrayLen(i,test)<<"\t"<< s.minSubArray(i, test) << endl;
    }
    
    system("pause");
}