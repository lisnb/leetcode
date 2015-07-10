#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.size() > s.size())
            return 0;
        if (t.size() == s.size())
            return t == s ? 1 : 0;

        vector<vector<int>> cache(t.size(), vector<int>(s.size(), 0));

        cache.at(0).at(0) = s.at(0) == t.at(0) ? 1 : 0;
        for (auto i = 1; i < s.size(); ++i)
            cache.at(0).at(i) = cache.at(0).at(i - 1) + (s.at(i) == t.at(0) ? 1 : 0);

        for (auto i = 1; i < t.size(); ++i)
        {
            for (auto j = i; j < s.size(); ++j)
            {
                if (t.at(i) == s.at(j))
                    cache.at(i).at(j) = cache.at(i).at(j-1) + cache.at(i-1).at(j-1);
                else
                    cache.at(i).at(j) = cache.at(i).at(j-1);
            }
        }

        return cache.back().back();
    }


    int numDistinctk(string s, string t)
    {
        if (t.size()>s.size())
            return 0;
        if (t.size() == s.size())
            return t == s ? 1 : 0;
        vector<int> cache(s.size(), 0);


    }
};


int main()
{
    Solution so;
    string s("rrabibbrb"), t("rb");
    cout << so.numDistinct(s, t) << endl;
    system("pause");
    return 0;
}