#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        return !wordBreak2(s, wordDict).empty();
    }
private:
    vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return{};
        size_t maxlen(0), minlen(s.size()), ssize(s.size());
        for (auto word : wordDict)
        {
            maxlen = max(maxlen, word.size());
            minlen = min(minlen, word.size());
        }

        vector<string> re;
        vector<string> prefix;
        unordered_map<size_t, bool> cache;
        workbreak(cache, s, 0, prefix, re, minlen, maxlen, wordDict);
        return re;
    }
private:

    bool workbreak(unordered_map<size_t, bool> &cache, const string &s, int ci, vector<string> &prefix, vector<string> &re, int minlen, int maxlen, unordered_set<string> &dict)
    {
        if (cache.find(ci) != cache.end() && !cache[ci])
            return false;
        if (ci == s.size())
        {
            stringstream ss;
            for (auto i = 0; i + 1 < prefix.size(); ++i)
                ss << prefix.at(i) << " ";
            ss << prefix.back();
            re.push_back(ss.str());
            return true;
        }
        bool suc = false;
        for (int len = minlen; len <= maxlen && ci + len - 1 < s.size(); ++len)
        {
            string tmp = s.substr(ci, len);
            if (dict.find(tmp) != dict.end())
            {
                prefix.push_back(tmp);
                bool t = workbreak(cache, s, ci + len, prefix, re, minlen, maxlen, dict);
                prefix.pop_back();
                if (t)
                    return t;
                cache[ci + len] = t;
                suc = suc || t;
            }
        }
        cache[ci] = suc;
        return suc;
    }
};


int main()
{
    Solution s;
    unordered_set<string> dict = { };
    string test("a");//test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    auto re = s.wordBreak(test, dict);
    cout << re << endl;
    system("pause");
    return 0;
}