#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size() + nums2.size());
        if (k & 0x1 != 0)
            return findmedian(nums1, 0, nums1.size() , nums2, 0, nums2.size(), k / 2+1);
        else
            return (findmedian(nums1, 0, nums1.size() , nums2, 0, nums2.size(), k / 2+1)
            +findmedian(nums1, 0, nums1.size(), nums2, 0, nums2.size() , k / 2 )) / 2.0;
    }
public:
    
    int findmedian(vector<int> &nums1, int b1, int l1, vector<int> &nums2, int b2, int l2, int k)
    {
        if (l1 > l2)
            return findmedian(nums2, b2, l2, nums1, b1, l1, k);
        if (l1==0)
            return nums2.at(b2 + k - 1);
        if (k == 1)
            return min(nums1.at(b1), nums2.at(b2));
        int pa = min(k / 2, l1);
        int pb = k - pa;
        if (nums1.at(b1+pa - 1) < nums2.at(b2+pb - 1))
            return findmedian(nums1, b1 + pa, l1 - pa, nums2, b2, l2, k - pa);
        else if (nums1.at(b1+pa - 1) > nums2.at(b2+pb - 1))
            return findmedian(nums1, b1, l1, nums2, b2 + pb, l2 - pb, k - pb);
        else
            return nums1.at(b1 + pa - 1);
    }
};

int main()
{
    Solution s;
    vector<int> n1 = {
        0,1,2,3
    };
    vector<int> n2 = {
        4, 5, 6, 7, 8, 9
    };
    cout << s.findMedianSortedArrays(n2, n1) << endl;

    system("pause");
}