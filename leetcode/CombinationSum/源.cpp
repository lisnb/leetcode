#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &num, int target) {
        re.clear();
        sort(num.begin(), num.end());
        vector<int> temp;
        combination(num, target, temp, 0);
        return re;
    }

    void combination(vector<int> &num, int target, vector<int> &prefix, int index)
    {
        if (index >= num.size())
            return;
        if (target == 0)
        {
            re.push_back(prefix);
            return;
        }
        int rl = num.size();
        for (auto i = index; i < rl; ++i)
        {
            if (num.at(i) > target)
                break;
            if (target == num.at(i))
            {
                prefix.push_back(target);
                re.push_back(prefix);
                prefix.pop_back();
                rl = i;
                break;
            }
        }
        int left(0);

        for (auto i = index; i < rl; ++i)
        {
            left = target - num.at(i);
            if (left < 0)
                return;
            prefix.push_back(num.at(i));
            combination(num, left, prefix, i);
            prefix.pop_back();
            while (i + 1 < num.size() && num.at(i) == num.at(i + 1))
                ++i;

        }



    }

private:
    vector<vector<int>> re;
};


int main()
{
    Solution s;
    vector<vector<int>> tests = {
        { 10, 1, 2, 7, 6, 1, 5 },
        {2,2, 3 ,6,7}
    };

    for (auto t : tests)
    {
        auto re = s.combinationSum(t, 7);
        for (auto re1 : re)
        {
            for (auto re2 : re1)
            {
                cout << re2 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    system("pause");
}