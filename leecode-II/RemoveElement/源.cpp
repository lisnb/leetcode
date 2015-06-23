#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        int p1(-1), p2(0);
        while (p2 < nums.size())
        {
            if (nums.at(p2) != val)
                swap(nums.at(++p1), nums.at(p2));
            ++p2;
        }
        return p1 + 1;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1, 1, 1, 1, 2, 2, 2, 2, 3 };
    cout << s.removeElement(test, 3) << endl;
    system("pause");
    return 0;
}