#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int lcsubstring(string &s1, string &s2)
{
    if (s1.empty() || s2.empty())
        return 0;
    int lcs(0);
    vector<vector<int>> opt(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 1; i<=s1.size(); ++i)
    {
        for (int j = 1; j<=s2.size(); ++j)
        {
            //opt[i][j] = s1[i-1] == s2[j-1] ? opt[i - 1][j - 1] + 1 : max(opt[i - 1][j], opt[i][j - 1]);

            opt[i][j] = s1[i-1] == s2[j-1] ?opt[i - 1][j - 1] + 1 : 0;
            lcs = max(lcs, opt[i][j]);
        }
    }
    return lcs;

}

int lcsubstring2(string &s1, string &s2)
{
    if (s1.empty() || s2.empty())
        return 0;
    int lcs(0);
    vector<int> opt(s2.size() + 1, 0);
    for (int i = 1; i <= s1.size(); ++i)
    {
        for (int j = 1; j <= s2.size(); ++j)
        {
            opt[j] = s1[i - 1] == s2[j - 1] ? opt[j - 1] + 1 : max(opt[j - 1], opt[j]);
        }
    }
    return opt.back();

}



int main()
{
    string s1("abcdefghijklmn"), s2("xyzghijopq"), s3("xaybzcoopdqqqesfm");
    //cout << lcsubstring(s1, s2) << endl;
    cout << lcsubstring2(s1, s3) << endl;
    system("pause");
    return 0;
}