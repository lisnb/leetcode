#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() < k || k==0)
            return{};
        int b(0), e(input.size() - 1);
        while (b <= e)
        {
            int pivot = partition(input, b, e);
            if (pivot == k)
                break;
            if (pivot > k)
                e = pivot - 1;
            else
                b = pivot + 1;
        }

        vector<int> re(input.begin(), input.begin() + k);
        return re;
    }


private:
    int partition(vector<int> &nums, int b, int e)
    {
        if (b >= e)
            return b;
        int p1(b), p2(b + 1);
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
    vector<int> test = { 4, 5, 1, 6, 2, 7, 3, 8 };
    auto re = s.GetLeastNumbers_Solution(test, 8);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}