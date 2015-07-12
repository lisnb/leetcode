#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;




class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4)
            return{};
        vector<string> prefix;
        vector<vector<string>> tre;
        vector<string> re;
        restore(s, 0, 1, prefix, tre);
        ostringstream ots;
        for (auto r : tre)
        {
            ots.str("");
            for (auto rs : r)
                ots << rs << '.';
            re.push_back(ots.str());
            re.back().pop_back();
        }
        return re;
    }

private:
    void restore(const string &s, int ci, int segcnt, vector<string> &prefix, vector<vector<string>> &re)
    {
        if (ci >= s.size())
        {
            return;
        }
        if (segcnt == 4)
        {
            string currentseg = s.substr(ci);
            if (isvalidipseg(currentseg))
            {
                re.push_back(prefix);
                re.back().push_back(currentseg);
            }
            return;
        }
        for (int i =0 ; i + ci < s.size() && i < 3; ++i)
        {
            string currentseg = s.substr(ci, i+1);
            if (!isvalidipseg(currentseg))
                continue;
            prefix.push_back(currentseg);
            restore(s, ci + i+1, segcnt + 1, prefix, re);
            prefix.pop_back();
        }

    }
    bool isvalidipseg(const string &seg)
    {
        if (seg == "0")
            return true;
        if (seg.at(0) == '0')
            return false;
        if (seg.size() > 3)
            return false;
        int iseg = stoi(seg);
        return iseg > 0 && iseg <= 255;
    }
};



int main()
{
    Solution s;
    string test("010010");
    auto re = s.restoreIpAddresses(test);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}