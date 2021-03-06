#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //return 0;
        auto a(nums1.size()), b(nums2.size());
        if ((a + b) % 2 == 1)
        {
            return findkthelement(nums1, 0, nums2, 0, (a + b) / 2 + 1);
        }
        else
        {
            double a1 = findkthelement(nums1, 0, nums2, 0, (a + b) / 2);
            double a2 = findkthelement(nums1, 0, nums2, 0, (a + b) / 2 + 1);
            return (a1 + a2) / 2;
        }
    }


    int findKthElement(vector<int> &num1, int s1, vector<int> &num2, int s2, int k)
    {
        if (num1.size() - s1 > num2.size() - s2)
            return findKthElement(num2, s2, num1, s1, k);
        if (s1 > (int)num1.size() - 1)
            return num2.at(s2 + k - 1);
        if (k == 1)
            return min(num1.at(s1), num2.at(s2));
        int pa = min(k / 2, (int)num1.size() - s1);
        int pb = k - pa;
        if (num1.at(pa + s1 - 1) < num2.at(pb + s2 - 1))
            return findKthElement(num1, s1 + pa, num2, s2, k - pa);
        else if (num1.at(pa + s1 - 1) > num2.at(pb + s2 - 1))
            return findKthElement(num1, s1, num2, s2 + pb, k - pb);
        else
            return num1.at(pa + s1 - 1);
    }


    int findkthelement(vector<int> &nums1, int s1, vector<int> &nums2, int s2, int k)
    {
        if ((int)nums1.size() - s1 > (int)nums2.size() - s2)
            return findkthelement(nums2, s2, nums1, s1, k);
        if (s1 >= nums1.size())
            return nums2.at(s2 + k - 1);
        if (k == 1)
            return min(nums1.at(s1), nums2.at(s2));
        int pa = min(k / 2, (int)nums1.size() - s1);
        int pb = k - pa;
        if (nums1.at(s1+pa-1) == nums2.at(s2+pb-1))
            return nums1.at(s1 + pa - 1);
        else if (nums1.at(pa+s1-1) > nums2.at(pb+s2-1))
            return findkthelement(nums1, s1, nums2, s2 + pb, k - pb);
        else
            return findkthelement(nums1, s1 + pa, nums2, s2, k - pa);
    }
};



int main()
{
    Solution s;

    vector<int> t1 = { 1}, t2 = { 2, 3, 5, 8, 11, 14 };
    //for (auto i = 1; i < t1.size() + t2.size() ;++i)
    cout << s.findKthElement(t1, 0, t2, 0, 4) << endl;
    //vector<int> t1, t2 = { 1 };
    //cout << s.findMedianSortedArrays(t2, t1) << endl;
    system("pause");
    return 0;
}