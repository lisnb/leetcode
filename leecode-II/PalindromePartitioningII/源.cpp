#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution3
{
public:
    int minCut(string s)
    {
        vector<int> dp(s.size() + 1, 0);
        vector<vector<int>> ispal(s.size() + 1, vector<int>(s.size() + 1, -1));
        for (int i = 1; i <= s.size(); ++i)
        {
            dp.at(i) = i;
            for (int j = 1; j <= i; ++j)
            {
                if (s.at(i - 1) == s.at(j - 1))
                {
                    if (i - j < 2 || ispal.at(j + 1).at(i - 1) == 0)
                    {
                        ispal.at(j).at(i) = 0;
                        if (j == 1)
                            dp.at(i) = 0;
                        else
                            dp.at(i) = min(dp.at(i), dp.at(j - 1) + 1);
                    }
                }
            }
        }
        return dp.at(s.size());
    }
};


class Solution2
{
public:
    int minCut(string s)
    {
        if (s.size() <= 1)
            return 0;
        vector<vector<int>> cache1(s.size(), vector<int>(s.size(), 0));
        vector<int> cache2(s.size(), -1);
        return dp(s, 0, cache1, cache2);
    }
private:

    int dp(string &s, int b, vector<vector<int>> &cache1, vector<int> &cache2)
    {
        if (b >= s.size())
            return 0;
        if (cache2.at(b) != -1)
            return cache2.at(b);
        int mincut(s.size());
        if (ispalindrome(s, b, s.size() - 1, cache1))
        {
            cache2.at(b) = 0;
            return 0;
        }
        for (int i = s.size() - 2; i >= b; --i)
        {
            if (ispalindrome(s, b, i, cache1))
            {
                mincut = min(mincut, dp(s, i + 1, cache1, cache2));
            }
        }
        cache2.at(b) = mincut + 1;
        return mincut + 1;
    }

    bool ispalindrome(string &s, int b, int e, vector<vector<int>> &cache)
    {
        if (cache.at(b).at(e) != 0)
            return cache.at(b).at(e) == 1;
        int bb(b), ee(e);
        while (bb < ee)
            if (s.at(bb++) != s.at(ee--))
            {
                cache.at(b).at(e) = -1;
                return false;
            }
        cache.at(b).at(e) = 1;
        return true;
    }
};

class Solution {
public:
    int minCut(string s) {
        vector<int> cache(s.size(), -1);
        return dp(s, 0, cache);
    }

private:
    int dp(string &s, int b, vector<int> &cache)
    {
        if (b >= s.size())
            return 0;
        if (cache.at(b) != -1)
            return cache.at(b);
        if (ispalindrome(s, b, s.size() - 1))
        {
            cache.at(b) = 0;
            return 0;
        }
        int mincut(s.size());
        for (int i = s.size()-2; i >=b;--i)
        {
            if (ispalindrome(s, b, i))
                mincut = min(mincut, dp(s, i + 1, cache));
        }
        cache.at(b) = mincut + 1;
        return mincut + 1;

    }
public:
    bool ispalindrome(string &s, int b, int e)
    {
        while (b < e)
            if (s.at(b++) != s.at(e--))
                return false;
        return true;
    }
};


int main()
{
    Solution2 s;
    //string test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    string test("abcbac");

    //cout << s.ispalindrome(test, 0, test.size()-1) << endl;
    cout << s.minCut(test) << endl;
    system("pause");
    return 0;
}