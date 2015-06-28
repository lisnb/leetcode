#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s(0);
        s = pivot(nums, s, 0);
        s = pivot(nums, s+1, 1);
    }
private:
    int pivot(vector<int> &nums, int s, int target)
    {
        int p1(s - 1), p2(s);
        while (p2 < nums.size())
        {
            if (nums.at(p2) <= target)
                swap(nums.at(++p1), nums.at(p2));
            ++p2;
        }
        return p1;
    }
};


int main()
{
    Solution s;
    //vector<int> test = { 2, 0, 1, 2, 2, 1, 0, 2, 1, 1, 0, 0, 0, 2, 2 };
    vector<int> test = { 2, 1 };
    s.sortColors(test);
    for (auto r : test)
        cout << r << " ";
    cout << endl;
    system("pause");
    return 0;
}