#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    bool isMatch(string s, string p) {

        return ismatch(s, s.size() - 1, p, p.size() - 1);

    }
private:

    bool ismatch(const string &s, int se, const string &p, int pe)
    {
        if (se == -1)
        {
            return matchempty(p, pe);
        }
        if (se >= 0 && pe < 0)
            return false;
        if (s.at(se) == p.at(pe) || p.at(pe) == '.')
            return ismatch(s, se - 1, p, pe - 1);
        if (p.at(pe) == '*')
        {
            if (pe == 0)
                return false;
            bool b = ismatch(s, se, p, pe - 2);
            if (b)
                return true;
            //at least use * once
            if (p.at(pe - 1) != s.at(se) && p.at(pe - 1) != '.')
                return false;
            else
                return ismatch(s, se - 1, p, pe);
        }
        else
            return false;
    }

    bool matchempty(const string &p, int pe)
    {
        if (pe<0)
            return true;
        if (p.at(pe) != '*')
            return false;
        if (pe == 0)
            return false;
        return matchempty(p, pe - 2);
    }
};

class SolutionWE {
public:
    bool isMatch(string s, string p) {
        return ismatch(s, s.size() - 1, p, p.size() - 1);
    }

private:


    bool ismatch(string s, int se, string p, int pe)
    {
        if (se >= 0 && pe < 0)
            return false;
        if (se < 0)
        {
            if (pe>0&&p.at(pe) == '*')
            {
                bool b = ismatch(s, se, p, pe - 2);
                if (b)
                    return true;
            }
            return pe < 0 || (pe == 1 && p.at(pe) == '*');
        }
        if (s.at(se) == p.at(pe) || p.at(pe) == '.')
            return ismatch(s, se - 1, p, pe - 1);
        if (p.at(pe) == '*')
        {
            while (pe-1 >= 0 && p.at(pe-1) == '*')
                --pe;
            if (pe == 0 )
                return false;
            bool b1 = ismatch(s, se, p, pe - 2);
            if (b1)
                return true;
            if (p.at(pe - 1) != s.at(se))
            {
                if (p.at(pe - 1) != '.')
                    return ismatch(s, se, p, pe - 2);
                else
                {
                    return ismatch(s, se , p, pe - 2) || ismatch(s, se - 1, p, pe);
                }
            }
            else
                return  ismatch(s, se - 1, p, pe);
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    Solution s;
    vector<string> ss = {
        "aa",
        "aa",
        "aa",
        "aaa",
        "aa",
        "aa",
        "ab",
        "aab"
    };
    vector<string> ps = {
        "b.*",
        "a",
        "aa",
        "aa",
        "a*",
        ".*",
        ".*",
        "c*a*b"
    };
    
    for (auto i = 7; i < ss.size(); ++i)
    {
        cout << ss.at(i) << " " << ps.at(i) << " " << s.isMatch(ss.at(i), ps.at(i)) << endl;
    }

    system("pause");
}