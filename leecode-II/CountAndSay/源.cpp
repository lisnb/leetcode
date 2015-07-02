#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
            return "";
        string tmp("1");
        while (n-- > 1)
        {
            tmp = saystring(tmp);
            //cout << tmp << endl;
        }
        return tmp;
    }

private:
    string saystring(string s)
    {
        if (s.empty())
            return "";
        size_t p(1), count(1);
        char cur(s.at(0)), last('\0');
        stringstream ss;
        while (p < s.size())
        {
            if (s.at(p) == cur)
            {
                ++count;
            }
            else
            {
                ss << count << cur;
                last = cur;
                cur = s.at(p);
                count = 1;
            }
            ++p;
        }
        if (cur != last)
        {
            ss << count << cur;
        }
        return ss.str();
    }
};


int main()
{
    Solution s;
    s.countAndSay(6);
    system("pause");
    return 0;
}