#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;



class Solution {
public:
    int reverseWithString(int x) {
        if (x == numeric_limits<int>::min())
            return 0;
        bool negtive = x < 0;
        long long number = x < 0 ? -x :  x;
        stringstream ss;
        ss << number;
        string snumber(ss.str());
        ::reverse(snumber.begin(), snumber.end());
        long long postnumber = stoll(snumber);
        if (negtive)
            postnumber *= -1;
        if (postnumber>numeric_limits<int>::max() || postnumber < numeric_limits<int>::min())
            return 0;
        return postnumber;
    }

    int reverse(int x)
    {
        if (x == numeric_limits<int>::min())
            return 0;
        bool negtive = x < 0;
        long long number = x < 0 ? -x : x;
        vector<short> digits;
        while (number>0)
        {
            digits.push_back(number % 10);
            number /= 10;
        }
        for (auto iter = digits.begin(); iter != digits.end(); ++iter)
            number = 10 * number + *iter;
        number *= negtive ? -1 : 1;
        return number > numeric_limits<int>::max() || number < numeric_limits<int>::min() ? 0 : number;
    }


    int reverseInteger(int x)
    {
        int ret(0);
        while (x > 0)
        {
            if (abs(ret) > 214748364)
                return 0;
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }
};


int main()
{
    Solution s;
    vector<int> test = {
        1, 2, 1234, -123, -1000000, 100, numeric_limits<int>::max(), numeric_limits<int>::min()
    };
    for (auto t:test)
        cout <<t<<"  " << s.reverse(t) << endl;
    system("pause");
    return 0;
}