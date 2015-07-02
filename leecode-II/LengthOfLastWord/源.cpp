#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        int p1(s.size()-1);
        while (p1 >= 0 && s.at(p1) == ' ')
            --p1;
        if (p1 == -1)
            return 0;
        int last(p1);
        while (p1 >= 0 && s.at(p1) != ' ')
            --p1;
        return last - p1;
    }
};


int main()
{
    Solution s;
    string test("  ");
    cout << s.lengthOfLastWord(test) << endl;
    system("pause");
    return 0;
}