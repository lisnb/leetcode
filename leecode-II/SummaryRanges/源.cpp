#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<string> re;
        int lb(0), ub(1);
        stringstream ss("");
        while (ub < nums.size())
        {
            while (ub < nums.size() && nums.at(ub) - nums.at(lb) == ub - lb)
                ++ub;
            if (ub == nums.size())
                break;
            ss.str("");
            if (lb == ub-1)
                ss << nums.at(lb);
            else
                ss << nums.at(lb) << "->" << nums.at(ub-1);
            re.push_back(ss.str());
            lb = ub++;
        }
        if (lb != nums.size())
        {
            ss.str("");
            if (lb == ub-1)
                ss << nums.at(lb);
            else
                ss << nums.at(lb) << "->" << nums.at(ub-1);
            re.push_back(ss.str());
        }
        return re;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 0};
    auto re = s.summaryRanges(test);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}