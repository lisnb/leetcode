#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int h = log2(m ^ n) + 1;
        return m & ~((1 << h) - 1);
    }

public:
    int rangebitwiseandWA(int m, int n)
    {
        int tm(m);
        int d(0);
        while (tm != 0)
        {
            tm >>= 1;
            ++d;
        }
        int mask = 1;
        mask <<= d;
        n = min(mask, n);
        tm = m;
        while (m <= n)
            tm &= ++m;
        return tm;

    }
};

int main()
{
    Solution s;
    cout << s.rangeBitwiseAnd(600000000, 2147483645) << endl;
    system("pause");
}