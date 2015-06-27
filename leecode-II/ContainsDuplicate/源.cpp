#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dict;
        for (auto n : nums)
            if (!dict.insert(n).second)
                return true;
        return false;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 4, 1 };
    cout << s.containsDuplicate(test) << endl;
    system("pause");
    return 0;
}