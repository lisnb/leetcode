#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <exception>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
            throw invalid_argument("x can't be less than 0");
        if (x == 0)
            return 0;
        long long lowerbound(1), upperbound(1);
        long long xx(x);
        while (upperbound*upperbound <= xx)
        {
            lowerbound = upperbound;
            upperbound *= 2;
        }
        if (lowerbound*lowerbound == x) 
            return lowerbound;
        while (lowerbound <= upperbound)
        {
            long long mid = lowerbound + (upperbound - lowerbound) / 2;
            long long tx = mid*mid;
            if (tx == xx)
                return mid;
            else if (tx > xx)
                upperbound = mid - 1;
            else
                lowerbound = mid + 1;
        }
        return lowerbound - 1;
    }
};



int main()
{
    Solution s;
    for (unsigned int i = 0x7ffffffa; i < 0x7fffffff; ++i)
        cout << i << " " << s.mySqrt(i) << endl;
    // << s.mySqrt(numeric_limits<int>::max()) << endl;
    system("pause");
    return 0;
}