#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;



class Solution {
public:
    string intToRoman(int num) {
        /*map<int, string> dict = {
            { 1000, "M"},
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "XI" },
            { 5, "V" },
            { 4, "VI" },
            { 1, "I" }
        };*/
        if (num <= 0)
            return string("");
        vector<int> digits = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> romans = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        ostringstream res;
        for (auto i = 0; i < digits.size();++i)
        {
            for (auto j = 0;j<num/digits.at(i);++j)
            {
                res << romans.at(i);
            }
            num %= digits.at(i);
        }
        return res.str();
    }
};



int main()
{
    Solution s;
    vector<int> test = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 38, 69, 190, 199, 3453, 2537 };
    for (auto t : test)
    {
        cout << t << "\t" << s.intToRoman(t) << endl;
    }

    system("pause");
}