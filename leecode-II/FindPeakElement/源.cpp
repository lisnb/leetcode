#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left < right)
        {
            cout << left << " " << mid << " " << right << endl;
            mid = (left + right) / 2;
            if (left == mid)
                return nums.at(left) > nums.at(right) ? left : right;
            if (nums[mid] < nums[mid + 1])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }

};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 1 };
    cout << s.findPeakElement(test) << endl;
    system("pause");
    return 0;
}