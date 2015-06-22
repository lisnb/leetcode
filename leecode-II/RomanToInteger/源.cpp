#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;



class Solution {
public:
    int romanToInt(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> rtoi = {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
        };

        int number(0);
        for (auto i = 0; i < s.size(); ++i)
        {
            if (i + 1 == s.size())
                number += rtoi.at(s.at(i));
            else
            {
                if (rtoi.at(s.at(i)) >= rtoi.at(s.at(i + 1)))
                    number += rtoi.at(s.at(i));
                else
                    number -= rtoi.at(s.at(i));
            }
        }
        return number;
    }
};


int main()
{
    Solution s;
    string test("MMDCLXXVIII");
    cout << s.romanToInt(test) << endl;
    system("pause");
    return 0;
}