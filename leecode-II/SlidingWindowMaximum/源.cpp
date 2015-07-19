#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> re;
        deque<int> maxes;
        if (nums.empty() || k > nums.size())
            return re;
        for (auto i = 0; i < k; ++i)
        {
            while (!maxes.empty( ) && nums.at(maxes.back()) <= nums.at(i))
                maxes.pop_back();
            maxes.push_back(i);
        }
        re.push_back(nums.at(maxes.front()));
        for (auto i = k; i < nums.size(); ++i)
        {
            while (!maxes.empty()&& maxes.front() <= i - k)
                maxes.pop_front();

            while (!maxes.empty() && nums.at(maxes.back())<nums.at(i))
            {
                maxes.pop_back();
            }
            maxes.push_back(i);
            re.push_back(nums.at(maxes.front()));
        }
        return re;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1, 3, -1, -3, 5, 3, 6, 7 };
    auto re = s.maxSlidingWindow(test, 1);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}