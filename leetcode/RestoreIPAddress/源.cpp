#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> tmp;
        if (s.size()<4)
            return tmp;
        restoreIpAddresses(s, 0, 1, tmp);
        stringstream ss;
        tmp.clear();
        for (auto r : re)
        {
            if (r.size() != 4)
                continue;
            ss.str("");
            ss << r[0] << "." << r[1] << "." << r[2] << "." << r[3];
            tmp.push_back(ss.str());
        }
        re.clear();
        return tmp;
    }
private:
    void restoreIpAddresses(const string &s, string::size_type b, int level, vector<string> &prefix)
    {
        if (b >= s.size() || (s.size() - b>3 * (4 - level + 1)))
            return;
        if (level == 4)
        {
            string left = s.substr(b);
            //cout<<"left: "<<left<<endl;
            if (isvalid(left))
            {
                prefix.push_back(left);
                re.push_back(prefix);
                prefix.pop_back();
                return;
            }
            else
                return;
        }
        for (auto i = 1; i<4; ++i)
        {
            string currentseg = s.substr(b, i);
            //cout<<"currentseg: "<<currentseg<<endl;
            if (isvalid(currentseg))
            {
                prefix.push_back(currentseg);
                restoreIpAddresses(s, b + i, level + 1, prefix);
                prefix.pop_back();
            }
        }
    }
    bool isvalid(const string &s)
    {
        if (s.size()>1 && s.at(0) == '0')
            return false;
        int number = atoi(s.c_str());
        return number <= 255;
    }
    vector<vector<string> > re;
};




int main()
{
    Solution s;
    vector<string> test = { "1061336", "10611121" };
    
    for (auto t : test)
    {
        cout << t << "\n[ ";
        for (auto tt : s.restoreIpAddresses(t))
        {
            cout << tt << ", ";
        }
        cout << " ]" << endl;;
    }

    system("pause");
}