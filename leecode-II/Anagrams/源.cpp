#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;




class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        if (strs.size() < 2)
            return{};
        unordered_map<string, vector<string>> cache;
        vector<string> re;
        re.reserve(strs.size());
        for (auto i = 0; i < strs.size(); ++i)
        {
            auto t = strs.at(i);
            sort(t.begin(), t.end());
            cache[t].push_back(strs.at(i));
        }

        for (auto kv : cache)
        {
            if (kv.second.size()>1)
                copy(kv.second.begin(), kv.second.end(), back_inserter(re));
        }
        return re;
    }
};



int main()
{
    Solution s;
    vector<string> test = { "abc", "cab", "abd", "aad", "daa", "dasf" };
    auto re = s.anagrams(test);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}