#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> re;
        if (candidates.empty() || target <= 0)
            return re;
        sort(candidates.begin(), candidates.end());
        vector<int> prefix;
        combination(candidates, re, prefix, 0, target);
        return re;
    }

private:

    void combination(const vector<int> &cans, vector<vector<int>> &re, vector<int> &prefix, int ci, int target)
    {
        for (auto i = ci; i < cans.size(); ++i)
        {
            if (target - cans.at(i) == 0)
            {
                prefix.push_back(cans.at(i));
                re.push_back(prefix);
                prefix.pop_back();
            }
            else if (target - cans.at(i) > 0)
            {
                prefix.push_back(cans.at(i));
                combination(cans, re, prefix, i, target - cans.at(i));
                prefix.pop_back();
            }
            while (i + 1 < cans.size() && cans.at(i) == cans.at(i + 1))
                ++i;
        }
    }



};



int main()
{
    Solution s;
    vector<int> test = {1, 2, 3, 6, 7 };
    auto re = s.combinationSum(test, 7);
    for (auto r : re)
    {
        for (auto rr : r)
            cout << rr << " ";
        cout << endl;
    }
    system("pause");
    return 0;

}