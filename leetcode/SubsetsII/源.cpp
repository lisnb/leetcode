#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> re;
        vector<int> tmp;
        subsets(re, S, 0, tmp);
        return re;
    }

    void subsets(vector<vector<int>> &re, vector<int> &S, vector<int>::size_type start, vector<int> &prefix)
    {
        re.push_back(prefix);
        if (start == S.size())
            return;
        for (auto b = start; b < S.size(); ++b)
        {
            prefix.push_back(S.at(b));
            subsets(re, S, b+1, prefix);
            prefix.pop_back();
            while (b + 1 < S.size() && S.at(b) == S.at(b + 1))
                ++b;
        }
    }
};

int main()
{
    Solution s;
    
    vector<int> test = {1,2,3,4};
    auto re = s.subsetsWithDup(test);
    cout << "count: " << re.size() << endl;
    for (auto t : re)
    {
        for (auto tt : t)
        {
            cout << tt << " ";
        }
        cout << endl;
    }
    system("pause");


}