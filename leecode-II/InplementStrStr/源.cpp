#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


class Solution{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        for (auto i = 0;; ++i)
        {
            for (auto j = 0;; ++j)
            {
                if (j == needle.size())
                    return i;
                if (i + j == haystack.size())
                    return -1;
                if (haystack.at(i+j) != needle.at(j))
                    break;
            }
        }
        return -1;
    }
};


int main()
{
    Solution s;
    string haystack("mississippi"), needle("mississippi");
    cout << s.strStr(haystack, needle);
    system("pause");
    return 0;
}