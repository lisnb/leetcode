#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        cache.clear();
        return isinterleave(s1, 0, s2, 0, s3, 0);
    }
private:
    unordered_map<string::size_type, unordered_map<string::size_type, bool>> cache;
    bool isinterleave(string s1, string::size_type b1, string s2, string::size_type b2, string s3, string::size_type b3)
    {
        if (cache.find(b1) != cache.end() && cache[b1].find(b2) != cache[b1].end())
            return cache[b1][b2];
        if (b1 == s1.size() && b2 == s2.size())
        {
            cache[b1][b2] = true;
            return true;
        }
        bool res;
        if (b1 == s1.size())
        {
            res = s2.substr(b2) == s3.substr(b3);
            cache[b1][b2] = res;
            return res;
        }
        if (b2 == s2.size())
        {
            res = s1.substr(b1) == s3.substr(b3);
            cache[b1][b2] = res;
            return res;
        }

        if (s1.at(b1) == s2.at(b2))
        {
            if (s1.at(b1) != s3.at(b3))
            {
                cache[b1][b2] = false;
                return false;
            }
            else
            {
                res = isinterleave(s1, b1 + 1, s2, b2, s3, b3 + 1) || isinterleave(s1, b1, s2, b2 + 1, s3, b3 + 1);
                cache[b1][b2] = res;
                return res;
            }
        }
        if (s1.at(b1) == s3.at(b3))
        {
            res =  isinterleave(s1, b1 + 1, s2, b2, s3, b3 + 1);
            cache[b1][b2] = res;
            return res;
        }
        if (s2.at(b2) == s3.at(b3))
        {
            res =  isinterleave(s1, b1, s2, b2 + 1, s3, b3 + 1);
            cache[b1][b2] = res;
            return res;
        }
        cache[b1][b2] = false;
        return false;
    }
};


int main()
{
    Solution s;
    auto s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    auto s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    auto s31 = "aadbbcbcac";
    auto s32 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    cout << s.isInterleave(s1, s2, s32) << endl;
    system("pause");
}