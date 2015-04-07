#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();

        map<char, bool> rec;
        int maxlen = 0;
        int b(0), e(0);
        for (auto i = 0; i < s.size(); ++i)
        {
            if (rec.find(s.at(i)) == rec.end())
            {
                rec[s.at(i)] = true;
                if (rec.size()>maxlen)
                {
                    maxlen = rec.size();
                }
            }
            else
            {
                while (s.at(b) != s.at(i))
                {
                    rec.erase(s.at(b));
                    ++b;
                }
                ++b;
            }
        }
        return maxlen;
    }
};

int main()
{
    Solution s;
    vector<string> test = { "abcabcbb", "bbbbbbb", "abcadecfbc" ,"a"};
    for (auto t : test)
    {
        cout << t << "\t" << s.lengthOfLongestSubstring(t) << endl;
    }
    system("pause");

}
