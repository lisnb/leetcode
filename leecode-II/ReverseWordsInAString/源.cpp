#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
public:
    string ReverseSentence(string str) {
        if (str.empty())
            return "";
        stringstream ss;
        int p1(str.size() - 1), p2(-1);
        while (p1 >= 0)
        {
            while (p1 >= 0 && str.at(p1) == ' ')
                --p1;
            if (p1 == -1)
                break;
            p2 = p1;
            while (p1 >= 0 && str.at(p1) != ' ')
                --p1;
            ss << str.substr(p1 + 1, p2 - p1) << ' ';
        }
        string s = ss.str();
        if (p2 >= 0)
            s.pop_back();
        else
            return str;
        return s;
    }
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
        //s.reverseWords3(t);
        cout<<s.ReverseSentence(t) << endl;
        cout << t << "|"<<endl;
    }
    system("pause");
    return 0;
}