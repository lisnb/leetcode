#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> chars = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> re;
        vector<int> answers(digits.size(), 0);
        vector<int> idigits;
        for (auto d : digits)
            idigits.push_back(d - '0');
        stringstream ss;
        while (true)
        {
            ss.str(string());
            for (auto i = 0; i < idigits.size() && answers.at(i)<chars.at(idigits.at(i)).size(); ++i)
            {
                ss << chars.at(idigits.at(i)).at(answers.at(i));
            }
            re.push_back(ss.str());

            int k = idigits.size() - 1;
            while (k >= 0)
            {
                if (answers.at(k)+1 < chars.at(idigits.at(k)).size())
                {
                    ++answers.at(k);
                    break;
                }
                else
                {
                    answers.at(k) = 0;
                    --k;
                }
            }
            if (k < 0)
                break;
        }
        return re;
    }
};


int main()
{
    Solution s;
    vector<string> tests = {
        "","234","1"
    };
    for (auto t : tests)
    {
        cout << t << endl;
        for (auto d : s.letterCombinations(t))
        {
            cout << d << endl;
        }
    }
    system("pause");
}