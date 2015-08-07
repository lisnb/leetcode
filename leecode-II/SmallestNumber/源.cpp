#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <functional>

using namespace std;



class Solution {
    struct cat_comp : public binary_function < int, int, bool >
    {
        bool operator()(int i1, int i2)
        {
            stringstream ss;
            ss << i1 << i2;
            string s1(ss.str());
            ss.str("");
            ss << i2 << i1;
            return s1 < ss.str();
        }
    };
public:
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.empty())
            return "";
        sort(numbers.begin(), numbers.end(), cat_comp());
        stringstream ss;
        for (auto num : numbers)
        {
            if (num != 0)
                ss << num;
        }
        return ss.str();
    }
};



int main()
{
    Solution s;
    vector<int> test = { 0, 3, 0, 30, 34, 5, 9, 0 };
    cout << s.PrintMinNumber(test) << endl;
    system("pause");
    return 0;
}