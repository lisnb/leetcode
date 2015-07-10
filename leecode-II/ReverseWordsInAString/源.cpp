#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        istringstream ss(s);
        vector<string> segs;
        string tmp("");
        while (ss >> tmp)
        {
            segs.push_back(tmp);
        }
        reverse(segs.begin(), segs.end());
        ostringstream oss;
        for (auto i = 0; i + 1 < segs.size(); ++i)
            oss << segs.at(i) << " ";
        oss << segs.back();
        //cout << oss.str() << endl;
        s = oss.str();
    }

    void reverseWords2(string &s) {
        stringstream ss(s);
        vector<string> segs;
        string tmp("");
        while (ss >> tmp) 
        {
            segs.push_back(tmp);
        }
        if (segs.empty())
        {
            s = "";
            return;
        }
        reverse(segs.begin(), segs.end());
        ss.str("");
        ss.clear();
        //stringstream ss;
        for (auto i = 0; i + 1 < segs.size(); ++i)
            ss << segs.at(i) << " ";
        ss << segs.back();
        //cout << oss.str() << endl;
        s = ss.str();
    }

    void reverseWords3(string &s)
    {
        int p2(s.size() - 1), p1(-1);
        stringstream ss;
        while (p2 >= 0)
        {
            while (p2 >= 0 && s.at(p2) == ' ')
                --p2;
            if (p2 < 0)
            {
                break;
            }
            p1 = p2;
            while (p2 >= 0 && s.at(p2) != ' ')
                --p2;
            ss << s.substr(p2 + 1, p1 - p2) << " ";
        }
        s = ss.str();
        if (p1 >= 0)
            s.pop_back();
    }
};


int main()
{
    Solution s;
    vector<string> test = { "   ",
        "the sky is blue",
        "   the ",
        "is a   ",
        "  sadf",
        "sadf sadf asdf  "
    };
    for (auto t : test)
    {
        cout << t << "|";
        s.reverseWords3(t);
        cout << t << "|"<<endl;
    }
    system("pause");
    return 0;
}