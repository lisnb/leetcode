#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;




class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordscnt(words.size());
        if (wordscnt == 0)
            return{};
        int wordsize(words.at(0).size());
        if (s.size() < wordscnt*wordsize)
            return{}; 
        vector<string> indices(s.size(), "");
        unordered_map<string, int> dict;
        for (auto word : words)
            ++dict[word];
        for (auto i = 0; i + wordsize - 1 < s.size(); ++i)
        {
            string tmp = s.substr(i, wordsize);
            if (dict.find(tmp) != dict.end())
                indices.at(i) = tmp;
        }
        vector<int> re;
        /*for (auto i = 0; i + wordscnt*wordsize - 1 < s.size(); ++i)
        {
            if (issub1(indices, dict, i, wordscnt, wordsize))
                re.push_back(i);
        }*/

        for (auto i = 0; i < wordsize; ++i)
        {
            issub2(indices, dict, i, wordscnt, wordsize, re, s.size());
        }
        return re;
    }
private:
    bool issub1(const vector<string>& indices, const unordered_map<string, int> &dict, int ci, int wordscnt, int wordsize)
    {
        unordered_map<string, int> dup(dict);
        for (auto i = 0; i < wordscnt; ++i)
            --dup[indices.at(ci + i*wordsize)];
        /*for (auto word : dup)
            if (word.second != 0)
                return false;
        return true;*/
        return ismatch(dup);
                
    }

    bool ismatch(const unordered_map<string, int> &dup)
    {
        for (auto word : dup)
            if (word.second != 0)
                return false;
        return true;
    }

    void issub2(const vector<string>& indices, const unordered_map<string, int> &dict, int ci, int wordscnt, int wordsize, vector<int> &re, int ssize)
    {
        unordered_map<string, int> dup(dict);
        for (auto i = 0; i < wordscnt; ++i)
            --dup[indices.at(ci + i*wordsize)];
        if (ismatch(dup))
            re.push_back(ci);
        int p1(ci), p2(ci + wordscnt*wordsize);
        while (p1 + (wordscnt+1)*wordsize - 1 < ssize)
        {
            ++dup[indices.at(p1)];
            --dup[indices.at(p2)];
            if (ismatch(dup))
                re.push_back(p1+wordsize);
            p1 += wordsize;
            p2 += wordsize;
        }
    }
};


int main()
{
    Solution s;
    vector<string> words = { "foo", "bar" };
    string st("barfoofoobarfoo");
    auto re = s.findSubstring(st, words);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}