#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k == 0&&n<k)
            return{};
        vector<int> nums;
        for (auto i = 1; i <= n; ++i)
            nums.push_back(i);
        if (n == k)
            return{ nums };
        vector<vector<int>> re;
        vector<int> prefix;
        backtrack(re, nums, prefix, 0, k);
        return re;

    }

private:
    void backtrack(vector<vector<int>> &re, const vector<int> &nums, vector<int> &prefix, int ci, int k)
    {
        if (k == 0)
        {
            re.push_back(prefix);
            return;
        }
        else
        {
            for (auto i = ci; i + k - 1 < nums.size(); ++i)
            {
                prefix.push_back(nums.at(i));
                backtrack(re, nums, prefix, i + 1, k - 1);
                prefix.pop_back();
            }
        }

    }
};

int main()
{
    Solution s;
    auto re = s.combine(4, 2);
    for (auto r : re)
    {
        for (auto rr : r)
            cout << rr << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}