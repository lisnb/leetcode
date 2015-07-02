#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;




class Solution {
public:
    vector<vector<string>> partition(string s) {
        int ssize(s.size());
        vector<vector<int>> grid(ssize, vector<int>(ssize, 0));
        for (auto i = 0; i < ssize; ++i)
        {
            for (auto j = i; j < ssize; ++j)
            {
                grid.at(i).at(j) = ispalindrome(s, i, j);
            }
        }
        
        vector<string> prefix;
        vector<vector<string>> re;
        backtrack(s, grid, prefix, re, 0, ssize);
        return re;

    }
private:
    void backtrack(const string &s, const vector<vector<int>> &grid, vector<string> &prefix, vector<vector<string>> &re, int ci, int ssize)
    {
        if (ci == ssize)
        {
            re.push_back(prefix);
            return;
        }
        for (auto i = ci; i < ssize; ++i)
        {
            if (grid.at(ci).at(i) == 0)
                continue;
            prefix.push_back(s.substr(ci, i - ci + 1));
            backtrack(s, grid, prefix, re, i + 1, ssize);
            prefix.pop_back();
        }
    }
private:
    bool ispalindrome(const string &s, int b, int e)
    {
        while (b < e)
        {
            if (s.at(b++) != s.at(e--))
                return false;
        }
        return true;
    }
};


int main()
{
    Solution s;
    string test("aabcba");
    auto re = s.partition(test);
    for (auto r : re)
    {
        for (auto rr : r)
            cout << rr << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}