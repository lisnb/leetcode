#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int p1(nums.size() - 1);
        while (p1 != 0 && nums.at(p1) <= nums.at(p1 - 1))
            --p1;
        if (p1 == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int p2(p1 - 1), pivot(nums.size());
        while (nums.at(--pivot) <= nums.at(p2));

        swap(nums.at(p2), nums.at(pivot));

        reverse(nums.begin() + p2 + 1, nums.end());
    }
};


int main()
{
    Solution s;
    vector<int> test = { 2, 3, 1, 3, 3};
    for (int i = 0; i < 20; ++i)
    {
        s.nextPermutation(test);
        for (auto t : test)
            cout << t << " ";
        cout << endl;
    }
    
    system("pause");
    return 0;
}