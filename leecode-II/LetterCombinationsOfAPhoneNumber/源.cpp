#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> re;
        if (digits.empty())
            return re;
        vector<string> phone = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string prefix("");
        combination(phone, re, digits, 0, prefix);
        return re;
    }


private:
    void combination(const vector<string> &phone, vector<string> &re, string digits, int di, string &prefix)
    {
        if (di == digits.size())
        {
            re.push_back(prefix);
            return;
        }
        size_t cd = digits.at(di) - '0';
        for (auto i = 0; i < phone.at(cd).size(); ++i)
        {
            prefix.push_back(phone.at(cd).at(i));
            combination(phone, re, digits, di + 1, prefix);
            prefix.pop_back();
        }
    }
};


int main()
{
    Solution s;
    string digits("2");
    auto re = s.letterCombinations(digits);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}