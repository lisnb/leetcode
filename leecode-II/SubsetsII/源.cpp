#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> re;
        vector<int> prefix;
        subset(nums, 0, prefix, re);
        return re;
    }
private:
    void subset(const vector<int> &nums, int ci, vector<int> &prefix, vector<vector<int>> &re)
    {
        
        re.push_back(prefix);
        if (ci == nums.size())
            return;
        for (auto i = ci; i < nums.size(); ++i)
        {
            prefix.push_back(nums.at(i));
            subset(nums, i + 1, prefix, re);
            prefix.pop_back();
            while (i + 1 < nums.size() && nums.at(i) == nums.at(i + 1))
                ++i;
        }
    }
};

int main()
{
    Solution s;
    vector<int> test = {  };
    auto re = s.subsetsWithDup(test);
    for (auto r : re)
    {
        for (auto rr : r)
            cout << rr << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}