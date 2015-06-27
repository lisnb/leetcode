#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return;
        k %= nums.size();
        reverse(nums, 0, nums.size() - k - 1);
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size());
    }
private:
    void reverse(vector<int> &nums, int b, int e)
    {
        while (b < e)
        {
            swap(nums.at(b++), nums.at(e--));
        }
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2 };
    s.rotate(test, 0);
    system("pause");
    return 0;
}