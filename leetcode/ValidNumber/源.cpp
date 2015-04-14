#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNumberWR(string s) {
        //trim it
        if (s.size() == 0)
            return false;
        int b(0), e(s.size() - 1);
        while (b < s.size() && s.at(b) == ' ')
            ++b;
        while (e >=0 && s.at(e) == ' ')
            --e;
        if (e < b)
            return false;
        int pointcnt = 0;
        int hexcnt = 0;
        int pncnt = 0;
        /*if (s.at(b) == '.' || s.at(e) == '.')
            return false;*/
        if (s.at(b) == 'e')
            return false;
        if (e == b && !isdigit(s.at(e)))
            return false;
        if (s.at(b) == '+' || s.at(e) == '-')
            ++b;
        bool epos = false;
        for (auto i = b; i <= e; ++i)
        {

            if (s.at(i) == '.')
            {
                if (epos)
                    return false;
                ++pointcnt;
                if (pointcnt > 1)
                    return false;
            }
            else if (isdigit(s.at(i)))
            {
                continue;
            }
            else if (s.at(i)=='e')
            {
                if (i == e)
                    return false;
                if (s.at(i + 1) == '+' || s.at(i + 1) == '-')
                    ++i;
                epos = true;
            }
            else
                return false;
        }

        if (hexcnt == e - b + 1)
            return false;
        return true;
    }

    bool isNumber(string s)
    {
        if (s.size() == 0)
            return false;
        int b(0), e(s.size() - 1);
        while (b < s.size() && s.at(b) == ' ')
            ++b;
        while (e >= 0 && s.at(e) == ' ')
            --e;
        if (e < b)
            return false;
        auto epos = s.find_first_of('e');
        if (epos == string::npos)
            return isfloat(s, b, e);
        else
        {
            if (epos == b)
                return false;
            return isfloat(s, b, epos - 1) && ispositivenumber(s, epos + 1, e);
        }
    }

    bool isfloat(string &s, int b, int e)
    {
        if (e < b)
            return false;
        if (s.at(b) == '+' || s.at(b) == '-')
            ++b;
        if (e == b )
            return isdigit(s.at(b));
        int pcnt = 0;
        for (auto i = b; i <= e; ++i)
        {
            if (s.at(i) == '.')
            {
                ++pcnt;
                if (pcnt > 1)
                    return false;
            }
            else if (isdigit(s.at(i)))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return b<=e;
    }

    bool ispositivenumber(string &s, int b, int e)
    {
        if (e < b)
            return false;
        if (e == b )
            return isdigit(s.at(b));
        if (s.at(b) == '+' || s.at(b) == '-')
            ++b;
        for (auto i = b; i <= e; ++i)
        {
            if (isdigit(s.at(i)))
                continue;
            else
                return false;
        }
        return b<=e;
    }
private:

    bool ishexalpha(char c)
    {
        return (c <= 'f' && c >= 'a') || (c <= 'F'&&c >= 'A');
    }
};


int main()
{
    Solution s;
    vector<string> tests = {
        "-e58",
        ".",
        "2e10",
        "3",
        " ",
        "   ",
        "0",
        " 0.1",
        "abc",
        "1 a",
        "2e10"
    };
    for (auto test : tests)
    {
        cout << test << "\t" << s.isNumber(test) << endl;
    }
    system("pause");
}