#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


class Solution {
public:
    struct comp_concat : public binary_function<int, int, bool>
    {
        bool operator() (const int lh, const int rh) const 
        {
            stringstream ss;
            ss << lh << rh;
            string s1(ss.str());
            ss.str("");
            ss << rh << lh;
            return s1 > ss.str();
        }
    };


public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp_concat());
        if (nums.empty() || nums.at(0) == 0)
            return "0";
        stringstream ss;
        for (auto num : nums)
            ss << num;
        return ss.str();
    }
};


int main()
{
    Solution s;
    vector<int> test = {0, 0 };
    cout << s.largestNumber(test) << endl;
    system("pause");
    return 0;
}