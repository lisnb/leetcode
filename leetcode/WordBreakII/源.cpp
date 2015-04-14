#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.size() == 0)
            return res;
        vector<string> prefix;

        wordbreak(s, wordDict, 0, prefix, res);

        return res;

    }

private:
    unordered_map<string::size_type, bool> cache;
    bool wordbreak(string &s, unordered_set<string> &dict, string::size_type index, vector<string> &prefix, vector<string> &res)
    {
        if (cache.find(index) != cache.end() && !cache[index])
            return false;
        if (index == s.size())
        {
            stringstream ss;
            for (auto i = 0; i < prefix.size()-1; ++i)
                ss << prefix.at(i) << " ";
            ss << prefix.back();
            res.push_back(ss.str());
            return true;
        }
        bool suc = false;
        for (auto i : dict)
        {
            if (equal(s, index, i))
            {
                prefix.push_back(i);
                bool br = wordbreak(s, dict, index + i.size(), prefix, res);
                prefix.pop_back();
                if (!br)
                    cache[index + i.size()] = false;
                if (br)
                    suc = br;
            }
        }
        cache[index] = suc;
        return suc;

    }

    bool equal(const string &s1, int b1, const string &s2)
    {
        if (s1.size() - b1 < s2.size())
            return false;
        auto i = 0;
        while (i < s2.size())
        {
            if (s1.at(b1 + i) != s2.at(i))
                return false;
            ++i;
        }
        return true;

    }
};


int main()
{
    Solution s;
    string str("aaaaaaa");
    unordered_set<string> dict = { "a", "aa", "aaaa" };
    auto res = s.wordBreak(str, dict);
    for (auto rere : res)
    {
        cout << rere << endl;
    }
    system("pause");
}