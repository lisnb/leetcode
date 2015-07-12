#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int b(0), e(s.size() - 1);
        while (b < e)
        {
            while (b <=e&&!isalnum(s.at(b)))
                ++b;
            if (b > e)
                return true;
            while (b <= e && !isalnum(s.at(e)))
                --e;
            if (b > e)
                return true;
            if (tolower(s.at(b)) != tolower(s.at(e)))
                return false;
            ++b;
            --e;
        }
        return true;
    }
};



int main()
{
    Solution s;
    vector<string> test = {
        "",
        " ",
        "  ",
        "   ",
        " d",
        "  d  ",
        "d   d   ",
        "A man, a plan, a canal: Panama",
        "race a car",
        "abb", 
        "1a2"
    };
    for (auto t : test)
        cout << t << "->" << s.isPalindrome(t) << endl;
    system("pause");
    return 0;
}