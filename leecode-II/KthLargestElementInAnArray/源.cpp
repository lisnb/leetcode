#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> nums, int k) {
        if (nums.size() < k)
            return -1;
        int b(0), e(nums.size() - 1);
        k = nums.size() - k;
        while (b<=e)
        {
            int mid = partition(nums, b, e);
            if (mid == k)
                return nums.at(mid);
            else if (mid > k)
                e = mid - 1;
            else
                b = mid + 1;
        }
        return nums.at(b);
    }

private:
   

    int partition(vector<int> &nums, int b, int e)
    {
        int p1(b);
        if (p1 >= e)
            return b;
        int p2 = p1 + 1;
        while (p2 <= e)
        {
            if (nums.at(p2) < nums.at(b))
                swap(nums.at(++p1), nums.at(p2));
            ++p2;
        }
        swap(nums.at(b), nums.at(p1));
        return p1;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6 };
    //vector<int> test = { 5, 2, 4, 1, 3, 6, 0 };
    for (auto i = 1; i <= test.size();++i)
        cout << i<<" "<<s.findKthLargest(test, i) << endl;
    system("pause");
    return 0;
}