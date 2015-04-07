#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;



class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return findit(num, 0, num.size() - 1);
    }

    int findPeakElementS(const vector<int> &num){
        int left = 0;
        int right = num.size() - 1;
        int mid = 0;
        while (left < right)
        {
            cout << left << " " << mid << " " << right << endl;
            mid = (left + right) / 2;
            if (num[mid] < num[mid+1])
            {
                left = mid;
            }
            else
            {
                right = mid + 1;
            }
        }
        return right;
    }

    int findit(const vector<int> &num, int b, int e)
    {
        if (b == 0 && e == 0)
            return 0;
        if (e - b == 1)
        {
            if (num[e] > num[b] && e == num.size() - 1)
            {
                return e;
            }
            if (num[e]<num[b] && b == 0)
            {
                return 0;
            }
            return -1;
        }
        else if (e < b)
        {
            return -e;
        }
        else
        {
            int p = (b + e) / 2;
            if (num[p] > num[p - 1] && num[p] > num[p + 1])
                return p;
            int pb = findit(num, b, p);
            int pe = findit(num, p, e);
            if (pb == -1 && pe == -1)
                return -1;
            return (pb == -1) ? pe : pb;
        }
    }
};


int main(){
    Solution s;
    vector<int> nums = { 3, 2,3};// 3,4,5,6,7,8,9,10};
    cout << s.findPeakElementS(nums) << endl;
    system("pause");
}