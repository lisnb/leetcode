#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() > t.size())
            return "";
        unordered_map<char, int> tmap;
        for (auto tc : t)
            ++tmap[tc];
        unordered_map<char, int> tmpmap(tmap);
        int p1(-1), int p2(0), minlen(s.size());
        while (p2 < s.size())
        {
            if (tmap.find(s.at(p2)) != tmap.end())
            {
                ++tmpmap[s.at(p2)];

            }
            else
            {

            }
        }

    }

private:
    bool ismatch()
    {
        return true;
    }
};




