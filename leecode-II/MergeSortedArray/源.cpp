#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        int index = m + n - 1;
        --m;
        --n;
        while (m >= 0 && n >= 0)
        {
            if (nums1.at(m) > nums2.at(n))
                nums1.at(index--) = nums1.at(m--);
            else
                nums1.at(index--) = nums2.at(n--);
        }
        if (m==-1)
        {
            while (index >= 0)
                nums1.at(index--) = nums2.at(n--);
        }
    }
};


int main()
{
    Solution s;
    vector<int> nums1 = { 2, 3, 4, 5, 6, 7, 40 };
    vector<int> nums2 = { 1, 4, 5, 6, 9, 20 };
    nums1.resize(nums1.size() + nums2.size());
    s.merge(nums1, 7, nums2, nums2.size());
    for (auto r : nums1)
        cout << r << " ";
    cout << endl;
    system("pause");
    return 0;
}