#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        radixsort(nums);
        int mg(-1);
        for (int i = 1; i < nums.size(); ++i)
        {
            mg = max(mg, nums.at(i) - nums.at(i - 1));
        }
        return mg;
    }


private:
    void radixsort(vector<int> &nums)
    {
        vector<int> backup(nums);
        int flipped = false;
        vector<int> bucket(10, 0);
        int maxsum = *max_element(nums.begin(), nums.end());
        int fac = 1;
        while (maxsum / fac > 0)
        {
            bucket.assign(10, 0);
            for (auto num : nums)
                ++bucket.at(num / fac % 10);
            for (auto i = 1; i < 10; ++i)
                bucket.at(i) += bucket.at(i - 1);
            if (flipped)
            {
                for (int i = nums.size() - 1; i >= 0; --i)
                {
                    nums.at(--bucket[backup.at(i) / fac % 10]) = backup.at(i);
                }
            }
            else
            {
                for (int i = nums.size() - 1; i >= 0; --i)
                {
                    backup.at(--bucket.at(nums.at(i) / fac % 10)) = nums.at(i);
                }
            }
            flipped = !flipped;
            fac *= 10;
        }
        if (flipped)
            copy(backup.begin(), backup.end(), nums.begin());
    }
};


int main()
{
    Solution s;
    vector<int> test = { 17, 14, 16, 18, 15, 23, 48, 171, 3456 };
    cout << s.maximumGap(test) << endl;
    system("pause");
    return 0;
}