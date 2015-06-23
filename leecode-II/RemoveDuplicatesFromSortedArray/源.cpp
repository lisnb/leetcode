#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int p1(0), p2(1);
        while (p2 < nums.size())
        {
            if (nums.at(p1) != nums.at(p2))
                swap(nums.at(++p1), nums.at(p2));
            ++p2;
        }
        return p1+1;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1,3, 3, 3, 5 };
    cout << s.removeDuplicates(test) << endl;
    system("pause");
    return 0;
}