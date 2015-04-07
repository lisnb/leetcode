#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

*/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> re;
        permute(num, re, 0);
        return re;
    }

    void permuteOLE(vector<int> &num, vector<vector<int>> &re, vector<int>::size_type i)
    {
        if (i == num.size() - 1)
        {
            re.push_back(num);
        }
        else
        {
            int t(0);
            for (auto j = i; j < num.size(); ++j)
            {
                if (i != j && (num.at(i) == num.at(j)))
                    continue;
                else
                {
                    t = num.at(i);
                    num.at(i) = num.at(j);
                    num.at(j) = t;
                    permuteOLE(num, re, i + 1);
                    t = num.at(i);
                    num.at(i) = num.at(j);
                    num.at(j) = t;
                }
            }
        }
    }

    void permute(vector<int> &num, vector<vector<int>> &re, vector<int>::size_type i)
    {
        // a b c d e f g
        // a 和其他所有的交换作为前缀，后面的全排列
        // 所以主要的是前缀，后面的顺序无关紧要，反正是全排列
        // 所以前缀只要不重复就行了
        if (i == num.size() - 1)
        {
            re.push_back(num);
            return;
        }
        unordered_set<int> set;
        for (auto j = i; j < num.size(); ++j)
        {
            if (set.find(num.at(j)) != set.end())
                continue;
            set.insert(num.at(j));
            swap(num.at(i), num.at(j));
            permute(num, re, i + 1);
            swap(num.at(i), num.at(j));
        }
    }
};


int main()
{
    Solution s;
    vector<int> test = {2,1,1,1,1,1};
    for (auto r : s.permuteUnique(test))
    {
        for (auto re : r)
        {
            cout << re << " ";
        }
        cout << endl;
    }
    system("pause");
}