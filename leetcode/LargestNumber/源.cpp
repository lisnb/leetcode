#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>


using namespace std;


class Solution {
public:
    string largestNumber(vector<int> &num) {
        if (num.empty())
            return string("");
        if (num.size() == 1)
            return to_string(num.at(0));
        vector<string> snums;
        for (auto n : num)
            snums.push_back(to_string(n));
        sort(snums.rbegin(), snums.rend(), scom2);
        if (snums.at(0) == "0")
            return 0;
        stringstream ss;
        for (auto s : snums)
            ss << s;
        return ss.str();
    }

private:
    static bool scom2(const string &l, const string &r)
    {
        string nl(l + r);
        string nr(r + l);
        return nl < nr;
    }
    static bool scom(const string &l, const string &r)
    {
        auto bl(0), br(0);
        while (bl < l.size() && br < r.size())
        {
            if (l.at(bl) < l.at(br))
                return true;
            else if (l.at(bl) > l.at(br))
                return false;
            else
            {
                ++bl;
                ++br;
            }
        }
        if (bl == l.size() && br == r.size())
            return false;
        else if (bl == l.size())
        {
            bl = 0;
            while (bl < l.size() && br < r.size())
            {
                if (l.at(bl) < l.at(br))
                    return true;
                if (l.at(bl) > l.at(br))
                    return false;
                else
                {
                    ++bl;
                    ++br;
                }
            }
            if (bl == l.size() && br == r.size())
                return false;
            else if (bl == l.size())
                return true;
        }
    }
};


int main()
{
    Solution s;
    vector<int> test = {0,0};
    cout << s.largestNumber(test) << endl;
    system("pause");
}

