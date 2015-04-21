#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //words中可以有duplicated words
        if (words.empty() || s.empty() || s.size() < words.at(0).size())
            return vector<int>();
        vector<int> re;
        unordered_map<string, int> dict;
        for (auto i = 0; i < words.size(); ++i)
        {
            ++dict[words.at(i)];
        }

        auto wordlen(words.at(0).size());
        string tmp("");
        unordered_map<int, string> indexes;
        for (auto i = 0; i < s.size() - wordlen + 1; ++i)
        {
            tmp = s.substr(i, wordlen);
            indexes[i] = tmp;
        }

        for (auto i = 0; i < s.size() - words.size()*wordlen + 1; ++i)
        {
            if (dict.find(indexes.at(i))==dict.end())
                continue;
            unordered_map<string, int> flags(dict);
            --flags[indexes.at(i)];
            bool in(true);
            for (auto j = 1; j < words.size(); ++j)
            {
                if (dict.find(indexes.at(i + wordlen*j)) == dict.end() || flags.at(indexes.at(i + wordlen*j))<=0)
                {
                    in = false;
                    break;
                }
                --flags.at(indexes.at(i + wordlen*j)) ;
            }
            if (in)
                re.push_back(i);
        }
        return re;
    }
    vector<int> findSubstringWA(string s, vector<string>& words) {
        //words中可以有duplicated words
        if (words.empty() || s.empty() || s.size() < words.at(0).size())
            return vector<int>();
        vector<int> re;
        unordered_map<string, int> dict;
        for (auto i = 0; i < words.size(); ++i)
            dict[words.at(i)] = i;
        auto wordlen(words.at(0).size());

        vector<int> indexes;
        string tmp("");
        for (auto i = 0; i < s.size() - wordlen + 1; ++i)
        {
            tmp = s.substr(i, wordlen);
            indexes.push_back(dict.find(tmp) == dict.end() ? -1 : dict[tmp]);
        }

        for (auto i = 0; i < s.size() - words.size()*wordlen + 1; ++i)
        {
            if (indexes.at(i) == -1)
                continue;
            vector<bool> flags(words.size(), false);
            flags.at(indexes.at(i)) = true;
            bool in(true);
            for (auto j = 1; j < words.size(); ++j)
            {
                if (indexes.at(i + wordlen*j) == -1 || flags.at(indexes.at(i + wordlen*j)))
                {
                    in = false;
                    break;
                }
                flags.at(indexes.at(i + wordlen*j)) = true;
            }
            if (in)
                re.push_back(i);
        }
        return re;
    }
};

int main()
{
    Solution s;
    //string ss("lingmindraboofooowingdingbarrwingmonkeypoundcake");
    //vector<string> words = { "fooo", "barr", "wing", "ding", "wing" };
    string ss("barfoothenfoobartbarfoo");
    vector<string> words = { "foo", "bar" };
    auto re = s.findSubstring(ss, words);

    for (auto rer : re)
        cout << rer << " ";
    system("pause");
}