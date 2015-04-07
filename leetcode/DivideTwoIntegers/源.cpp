#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        long long ldividend(dividend), ldivisor(divisor);
        bool np = true;
        if (dividend < 0)
        {
            ldividend = -ldividend;
            np = !np;
        }
        if (divisor < 0)
        {
            ldivisor = -ldivisor;
            np = !np;
        }

        if (ldivisor > ldividend)
            return 0;
        if (ldividend == ldivisor)
            return np ? 1 : -1;
        long long  re = dividel(ldividend, ldivisor);
        re = np ? re : -re;
        if (re > INT_MAX || re < INT_MIN)
            return INT_MAX;
        return re; 
    }

    long long  dividel(long long dividend, long long divisor)
    {
        long long fac = 1;
        long long od(divisor);
        long long re = 0;
        while (dividend >= divisor)
        {
            dividend -= divisor;
            divisor <<= 1;
            re += fac;
            fac <<= 1;
        }
        while (dividend>=od)
        {
            if (dividend == divisor)
                return re + fac;
            divisor >>= 1;
            fac >>= 1;
            
            if (dividend > divisor)
            {
                dividend -= divisor;
                re += fac;
            }
        }
        return re;
    }
};





int main()
{
    int max = INT_MAX;
    int min = INT_MIN;
    cout << max << endl;
    cout << min << endl;

    cout << max / min << endl;
    cout << min / max << endl;
    cout << max / (min + 1) << endl;

    cout << 0 - max << endl;
    cout << 0 - min << endl;

    cout << max + 1 << endl;


    long long lmin = min;
    cout << lmin << endl;

    //cout << min / -1 << endl;

    Solution s;
    //vector<pair<int, int>> test = { { 10, 1 }, { 20, 2 }, { 100, 20 }, { 100, 102 }, { 100, 100 }, { INT_MAX, INT_MIN }, { INT_MIN, INT_MAX }, { INT_MIN, 1 }, { INT_MAX, 1 } };
    vector<pair<int, int>> test = { { -2147483648, 2 }, { -2147483648, 1 }, { -1, 1 },/*{ -2147483648, -3 }, { 100, 3 }, { INT_MAX, INT_MIN }, { INT_MIN, INT_MAX },*/{ INT_MIN, -1 }, { INT_MAX, 1 } };

    for (auto t : test)
    {
        cout << t.first << "/" << t.second << "=" << s.divide(t.first, t.second) << endl;
    }
    system("pause");
}