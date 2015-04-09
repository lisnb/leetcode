#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        cache.clear();
        return editdistance(word1, 0, word2, 0);
    }

private:
    unordered_map<string::size_type, unordered_map<string::size_type, int>> cache;
    int editdistance(string word1, string::size_type s1, string word2, string::size_type s2)
    {
        if (cache.find(s1) != cache.end() && cache[s1].find(s2) != cache[s1].end())
            return cache[s1][s2];
        int mined(-1);
        if (s1 >= word1.size())
        {
            if (s2 >= word2.size())
            {
                cache[s1][s2] = 0;
                return 0;
            }
            else
            {
                mined = word2.size() - s2;
                cache[s1][s2] = mined;
                return mined;
            }
        }

        if (s2 >= word2.size())
        {
            mined = word1.size() - s1;
            cache[s1][s2] = mined;
            return mined;
            
        }
        if (word1.at(s1) == word2.at(s2))
        {
            mined = editdistance(word1, s1 + 1, word2, s2 + 1);
            cache[s1][s2] = mined;
            return mined;
        }
        int ed1 = editdistance(word1, s1 + 1, word2, s2 + 1);
        int ed2 = editdistance(word1, s1 + 1, word2, s2);
        int ed3 = editdistance(word1, s1, word2, s2 + 1);

        mined = min({ ed1+1, ed2+1, ed3+1 });
        cache[s1][s2] = mined;
        return mined;
    }
};


int main()
{
    Solution s;
    vector<pair<string, string>> tests = {
        {"a","ab"},
        { "ab", "abc" },
        { "fluid", "fluent" },
        { "dinitrophenylhydrazine", "acetylphenylhydrazine"}
    };

    for (auto t : tests)
    {
        cout << t.first << " " << t.second << ": " << s.minDistance(t.first, t.second) << endl;
    }

    system("pause");
}