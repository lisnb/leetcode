#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int duplicateNumber(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) == i)
                continue;
            if (nums.at(i) >= nums.size())
                return -1;
            if (nums.at(i) == nums.at(nums.at(i)))
                return nums.at(i);
            swap(nums.at(i), nums.at(nums.at(i)));
            --i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 4,3, 2, 1, 0};
    cout << s.duplicateNumber(test) << endl;
    system("pause");
    return 0;
}