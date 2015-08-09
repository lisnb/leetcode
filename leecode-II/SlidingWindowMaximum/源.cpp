#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>
#include <queue>

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

class Solution2 {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if (num.empty() || size == 0)
            return{};
        if (num.size() <= size)
            return{ *max_element(num.begin(), num.end()) };
        deque<int> mindex;
        for (auto i = 0; i + 1<size; ++i)
        {
            while (!mindex.empty() && num.at(mindex.back()) <= num.at(i))
                mindex.pop_back();
            mindex.push_back(i);
        }

        vector<int> re;
        for (auto i = size - 1; i<num.size(); ++i)
        {
            while (!mindex.empty() && mindex.front() + size <= i)
                mindex.pop_front();
            while (!mindex.empty() && num.at(mindex.back()) <= num.at(i))
                mindex.pop_back();
            mindex.push_back(i);
            re.push_back(num.at(mindex.front()));
        }
        return re;

    }
};

int main()
{
    Solution2 s;
    vector<int> test = { 1, 3, -1, -3, 5, 3, 6, 7 };
    //auto re = s.maxSlidingWindow(test, 1);
    auto re = s.maxInWindows(test, 3);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}