#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        unordered_map<int, int> cache;
        return decode(s, cache, 0);
    }

private:
    int decode(const string &s, unordered_map<int, int> &cache, int ci)
    {
        if (cache.find(ci) != cache.end())
            return cache[ci];
        if (ci == s.size())
            return 1;
        if (ci > s.size() || s.at(ci) == '0')
            return 0;
        int ways(0);
        if (ci == s.size() - 1)
        {
            ways = 1;
        }
        else if (s.at(ci) == '1')
        {
            ways = decode(s, cache, ci + 1) + decode(s, cache, ci + 2);
        }
        else if (s.at(ci) == '2')
        {
            if (s.at(ci + 1) <= '6')
                ways = decode(s, cache, ci + 1) + decode(s, cache, ci + 2);
            else
                ways = decode(s, cache, ci + 1);
        }
        else
            ways = decode(s, cache, ci + 1);
        cache[ci] = ways;
        return ways;
    }
};




class Solution2 {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        if (s.at(0) == '0')
            return 0;
        int ci_1(1), ci_2(1), ci(1);
        for (auto i = 1; i < s.size(); ++i)
        {
            if (s.at(i - 1) == '1')
            {
                ci = s.at(i) == '0' ? ci_2 : (ci_1 + ci_2);
            }
            else if (s.at(i - 1) == '2')
            {
                ci = s.at(i) == '0' ? ci_2 : s.at(i) > '6' ? ci_1 : (ci_1 + ci_2);
            }
            else
                ci = s.at(i) == '0' ? 0 : ci_1;

            ci_2 = ci_1;
            ci_1 = ci;
        }
        return ci;
    }

private:
};

int main()
{
    Solution2 s;
    string test("1122");
    cout << s.numDecodings(test) << endl;
    system("pause");
    return 0;

}