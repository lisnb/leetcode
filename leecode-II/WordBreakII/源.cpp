#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;


class Solution2 {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty())
            return{};
        size_t maxlen(0), minlen(s.size()), ssize(s.size());
        for (auto word : wordDict)
        {
            maxlen = max(maxlen, word.size());
            minlen = min(minlen, word.size());
        }

        vector<vector<int>> grid(ssize, vector<int>(ssize, 0));

        for (auto i = 0; i < s.size(); ++i)
            for (auto j = i + minlen - 1;j<min(s.size(), i+maxlen); ++j)
            {
                grid.at(i).at(j) = indict(wordDict, s, i, j);
            }
        vector<vector<string>> tre;
        vector<string> prefix;
        backtrack(s, grid, prefix, tre, 0, ssize, minlen, maxlen);
        vector<string> re;
        re.reserve(tre.size()); 
        for (auto rr : tre)
            re.push_back(format(rr));
        return re;

    }
private:
    bool indict(const unordered_set<string> &wordDict, const string &s, int b, int e)
    {
        if (b > e)
            return false;
        string tmp(s.substr(b, e - b + 1));
        return wordDict.find(tmp) != wordDict.end();
    }

    void backtrack(const string &s, const vector<vector<int>> &grid, vector<string> &prefix, vector<vector<string>> &re, int ci, int ssize, int minlen, int maxlen)
    {
        if (ci == ssize)
        {
            re.push_back(prefix);
            return;
        }
        for (auto i = ci + minlen - 1; i < ssize; ++i)
        {
            if (grid.at(ci).at(i) != 0)
            {
                prefix.push_back(s.substr(ci, i - ci + 1));
                backtrack(s, grid, prefix, re, i + 1, ssize, minlen, maxlen);
                prefix.pop_back();
            }
        }
    }

    string format(const vector<string> &segs)
    {
        stringstream ss;
        for (auto i = 0; i + 1 < segs.size(); ++i)
            ss << segs.at(i) << " ";
        ss << segs.back();
        return ss.str();
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty())
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
    unordered_set<string> dict = { "abbcbda", "cbdaaa", "b", "dadaaad", "dccbbbc", "dccadd", "ccbdbc", "bbca", "bacbcdd", "a", "bacb", "cbc", "adc", "c", "cbdbcad", "cdbab", "db", "abbcdbd", "bcb", "bbdab", "aa", "bcadb", "bacbcb", "ca", "dbdabdb", "ccd", "acbb", "bdc", "acbccd", "d", "cccdcda", "dcbd", "cbccacd", "ac", "cca", "aaddc", "dccac", "ccdc", "bbbbcda", "ba", "adbcadb", "dca", "abd", "bdbb", "ddadbad", "badb", "ab", "aaaaa", "acba", "abbb" };
    string test("acaaaaabbbd");//test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    auto re = s.wordBreak(test, dict);
    for (auto rr : re)
        cout << rr << endl;
    system("pause");
    return 0;
}