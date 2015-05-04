#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0 || s.size()<t.size())
            return string("");
        if (t.size() == 1)
            return s.find(t) == s.npos ? "" : t;
        auto b = s.find_first_of(t);
        auto e = s.find_last_of(t);
        if (b == string::npos || e == string::npos)
            return string("");
        unordered_map<char, int> sus;
        for (auto c : t)
            ++sus[c];
        unordered_map<char, int> rus;
        queue<int> index;
        auto p1(b), p2(b+1);
        rus[s.at(b)] = 1;
        int minwindow(INT_MAX);
        int p11(-1), p22(-1); 
        while (p2 < s.size())
        {
            if (sus.find(s.at(p2)) != sus.end())
            {
                index.push(p2);
                while(rus[s.at(p2)]>sus[s.at(p2)]&&s.at(p2) == s.at(p1)&&!index.empty())
                {
                    p1 = index.front();
                    index.pop();
                }
                ++rus[s.at(p2)];
                if (rus == sus)
                {
                    if (p2 - p1 +1 < minwindow)
                    {
                        minwindow = p2 - p1+1;
                        p11 = p1;
                        p22 = p2;
                    }
                    --rus[s.at(p1)];
                    if (!index.empty())
                    {
                        p1 = index.front();
                        index.pop();
                    }
                }
            }
            ++p2;
        }
        while (!index.empty())
        {
            --rus[s.at(p1)];
            p1 = index.front();
            index.pop();
            if (rus == sus)
            {
                if (p2 - p1 + 1 < minwindow)
                {
                    minwindow = p2 - p1 + 1;
                    p11 = p1;
                    p22 = p2;
                }
            }
        }
        return p11 == -1 ? "" : s.substr(p11, p22 - p11 + 1);
    }
};

int main()
{
    Solution s;
    string ss("bbaac");
    string t("aba");
    cout << ss << " " << t << " " << s.minWindow(ss, t) << endl;
    system("pause");
}
