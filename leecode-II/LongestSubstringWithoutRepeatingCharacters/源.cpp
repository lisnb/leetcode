#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        vector<int> positions(255, -1);
        int start(0), lss(0), cpos(0);
        for (auto i = 0; i < s.size(); ++i)
        {
            cpos = s.at(i);

            if (positions.at(cpos) >= start)
            {
                lss = max(i - start, lss);
                start = positions.at(cpos) + 1;
            }
            positions.at(cpos) = i;
        }
        //lss = max(s.size() - start, lss);
        return max((size_t)lss, s.size() - start);
    }
};

int main()
{
    Solution s;

    string test("aababc");

    cout << s.lengthOfLongestSubstring(test) << endl;
    system("pause");
    return 0;
}