#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    bool isMatchMLE(string s, string p) {
        vector<vector<int>> grid(p.size() + 1, vector<int>(s.size() + 1, 0));
        grid.at(0).at(0) = 1;
        auto jj = 0;
        for (auto i = 0; i < p.size(); ++i)
        {
            if (p.at(i) == '*')
            {
                int j(0);
                while (j < s.size() && grid.at(i).at(j + 1) == 0)
                    ++j;
                for (; j < s.size(); ++j)
                    grid.at(i + 1).at(j + 1) = 1;
            }
            else
            {
                for (auto j = 0; j < s.size(); ++j)
                {
                    if (grid.at(i).at(j) == 0)
                        grid.at(i + 1).at(j + 1) = 0;
                    else
                        grid.at(i + 1).at(j + 1) = (p.at(i) == '?' || p.at(i) == s.at(j)) ? grid.at(i).at(j) : 0;
                }
            }

        }
        return grid.back().back();
    }


    bool isMatchWA(string s, string p)
    {
        int asterisk(0);
        for (auto i = 0; i < p.size(); ++i)
            asterisk += (p.at(i) == '*' ? 1 : 0);
        if (p.size()>s.size() + asterisk)
            return false;
        vector<int> cache(s.size() + 1, 0);
        cache.at(0) = 1;
        for (auto i = 0; i < p.size(); ++i)
        {
            if (p.at(i) == '*')
            {
                int j(0);
                while (j < s.size() && cache.at(j) == 0)
                    ++j;
                for (; j <= s.size(); ++j)
                    cache.at(j) = 1;
            }
            else
            {
                for (int j=s.size()-1; j>=0; --j)
                {
                    if (cache.at(j) == 0)
                        cache.at(j + 1) = 0;
                    else
                        cache.at(j + 1) = p.at(i) == '?' || p.at(i) == s.at(j) ? cache.at(j) : 0;
                }
            }
            
        }
        return cache.back();

    }

    bool isMatchWA3(string s, string p)
    {
        size_t asteristk(0);
        for (auto c : p)
            asteristk += (c == '*' ? 1 : 0);
        if (s.size() + asteristk < p.size())
            return false;
        vector<bool> cache(s.size() + 1, false);
        cache.at(0) = true;
        for (auto i = 0; i < p.size(); ++i)
        {
            if (p.at(i) == '*')
            {
                int j(0);
                while (j < s.size() && !cache.at(j))
                    ++j;
                for (; j < s.size(); ++j)
                    cache.at(j+1) = true;
            }
            else
            {
                for (auto j = 0; j < s.size(); ++j)
                    cache.at(j + 1) = cache.at(j) && (s.at(j) == p.at(i) || p.at(i) == '?');
            }
        }
        return cache.back();
    }


    bool isMatch(string s, string p)
    {
        size_t asteristk(0);
        for (auto c : p)
            asteristk += (c == '*' ? 1 : 0);
        if (s.size() + asteristk < p.size())
            return false;
        vector<bool> cache(s.size() + 1, false);
        cache.at(0) = true;
        cout << "  ";
        for (auto k = 0; k < cache.size(); ++k)
            cout << cache.at(k) << " ";
        cout << endl;
        for (int i = 0; i <p.size(); ++i)
        {
            cout << p.at(i) << " ";
            
            if (p.at(i) == '*')
            {
                int j(0);
                while (j <= s.size() && !cache.at(j))
                    ++j;
                for (; j < s.size(); ++j)
                    cache.at(j+1) = true;
            }
            else
            {
                for (int j = s.size() - 1; j >= 0; --j)
                    cache.at(j + 1) = cache.at(j) && (p.at(i) == '?' || p.at(i) == s.at(j));
            }
            for (auto k = 0; k < cache.size(); ++k)
                cout << cache.at(k) << " ";
            cout << endl;
            cache.at(0) = cache.at(0) && p.at(i) == '*';
        }
        return cache.back();
    }
};


int main()
{
    Solution so;
    string s("mississippi"), p("m*issi*iss*");
    auto r = so.isMatch(s, p);
    cout << r << endl;
    system("pause");
    return 0;
}