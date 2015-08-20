#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mapst[256] = { '\0' };
        char mapts[256] = { '\0' };
        for (int i = 0; i<s.size(); ++i)
        {
            if (mapst[s[i]] == '\0'&&mapts[t[i]] == '\0')
            {
                mapst[s[i]] = t[i];
                mapts[t[i]] = s[i];
            }
            else if (mapst[s[i]] == t[i] && mapts[t[i]] == s[i])
                continue;
            else
                return false;

        }
        return true;
    }
};

int main()
{
    Solution so;
    string s("aa"), t("bb");
    cout << so.isIsomorphic(s, t) << endl;
    return 0;
}