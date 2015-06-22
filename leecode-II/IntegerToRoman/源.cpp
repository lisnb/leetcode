#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;



class Solution {
public:
    string intToRoman(int num) {
        if (num <= 0)
            return "";
        /*unordered_map<int, string> itor = {
            { 1000, "M" },
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "IX" },
            { 5, "VX" },
            { 4, "IV" },
            { 1, "I" }
        };*/
        vector<int> digits = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> romans = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        stringstream ss;
        for (auto i = 0; i < digits.size(); ++i)
        {
            auto cnt = num / digits.at(i);
            for (auto j = 0; j < cnt; ++j)
                ss << romans.at(i);
            num %= digits.at(i);
        }
        
        return ss.str();
    }
};



int main()
{
    Solution s;
    vector<int> tests = { 2316, 2678, 1983 };
    for (auto test : tests)
        cout << test << " " << s.intToRoman(test) << endl;
    system("pause");
    return 0;
}