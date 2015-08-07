#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Solution
{
public:
    string matchsequence(int n)
    {
        vector<string> matches(n);
        for (auto i = 1; i <= n; ++i)
            matches.at(i - 1) = to_string(i);
        while (n > 1)
        {
            for (auto i = 0; i < n / 2; ++i)
                matches.at(i) = "(" + matches.at(i) + "," + matches.at(n - i - 1) + ")";
            n /= 2;
        }
        return matches.front();
    }

    string matchsequence2(int t, int r, int a)
    {
        if (2<<(r-1) > a)
            return to_string(t);
        int rr = 1 << r;
        ++rr;
        string s1 = matchsequence2(t, r + 1, a);
        string s2 = matchsequence2(rr - t, r + 1, a);
        return "(" + s1 + "," + s2 + ")";
    }
private:
    string match(string &t1, string &t2)
    {
        return "(" + t1 + "," + t2 + ")";
    }
};


int main()
{
    Solution s;
    //auto r = s.matchsequence(16);
    auto r = s.matchsequence2(1, 1, 16);
    cout << r << endl;
    system("pause");
    return 0;
}