#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;




class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs.at(0);
        size_t lcp(0);
        while (true)
        {
            if (lcp == strs.at(0).size())
                return strs.at(0);
            for (auto i = 1; i < strs.size();++i)
            {
                if (lcp == strs.at(i).size())
                    return strs.at(i);
                if (strs.at(i).at(lcp) != strs.at(0).at(lcp))
                    return lcp==0?"":strs.at(0).substr(0, lcp);
            }
            ++lcp;
        }
    }
};

int main()
{
    Solution s;
    //string ss("abc");
    //cout << ss.substr(0, -1) << endl;
    vector<string> test = {
        "abcdef",
        "cd"
        //"abadsf",
        //"acasdf"
    };
    cout << s.longestCommonPrefix(test) << endl;
    system("pause");
    return 0;
}