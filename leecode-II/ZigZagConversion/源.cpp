#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;




class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= 1 || numRows <= 1)
            return s;
        vector<string> rows(numRows);
        size_t crow(0), ci(0);
        bool go(true);
        while (ci < s.size())
        {
            rows.at(crow).push_back(s.at(ci));
            crow += go ? 1 : -1;
            if (crow == numRows)
            {
                crow -= 2;
                go = false;
            }
            if (crow == -1)
            {
                crow += 2;
                go = true;
            }
            ++ci;
        }

        stringstream ss;
        for (auto row : rows)
            ss << row;
        return ss.str();
    }
};


int main()
{
    Solution s;
    string ss("paypalishiring");
    for (auto i = 1; i < 10;++i)
        cout << s.convert(ss, i) << endl;
    system("pause");
    return 0;
}