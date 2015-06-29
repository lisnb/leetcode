#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp(0);
        for (auto num : nums)
            tmp ^= num;
        return tmp;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7 };
    cout << s.singleNumber(test) << endl;
    system("pause");
    return 0;
}