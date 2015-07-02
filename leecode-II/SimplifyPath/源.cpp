#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;




class Solution {
public:
    string simplifyPath(string path) {
        vector<string> segs;
        strsplit(path, segs);
        vector<string> stack;
        for (auto seg : segs)
        {
            cout << seg << endl;
            if (seg == ".")
                continue;
            else if (seg == "..")
            {
                if (stack.empty())
                    continue;
                else
                    stack.pop_back();
            }
            else
                stack.push_back(seg);
        }
        if (stack.empty())
            return "/";
        stringstream ss;
        for (auto seg : stack)
            ss << '/' << seg;
        return ss.str();
    }

private:
    void strsplit(const string &s, vector<string> &re)
    {
        string::size_type currentslash(0), lastslash(0);
        string tmp("");
        while (true)
        {
            currentslash = s.find('/', lastslash);
            if (currentslash == string::npos)
            {
                if (lastslash  < s.size())
                {
                    tmp = s.substr(lastslash, re.size() - lastslash - 1);
                    re.push_back(tmp);
                }
                return;
            }
            if (currentslash - lastslash > 0)
            {
                tmp = s.substr(lastslash, currentslash - lastslash);
                re.push_back(tmp);
            }
            lastslash = currentslash+1;
        }
    }
};

int main()
{
    Solution s;
    string test("/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e");
    cout<< s.simplifyPath(test)<<endl;
    system("pause");
    return 0;
}