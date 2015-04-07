#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdint>
#include <limits>
using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t re = 0;
        int i = 0;
        while (i < 32)
        {
            re <<= 1;
            re |= (n & 1);
            n >>= 1;
            i++;
        }
        return re;
    }
};

void bit(uint32_t n)
{
    short fac = 2;
    while (n > 0)
    {
        /*cout << n % 2;
        n /= 2;*/
        cout << (n & 1);
        n >>= 1;
    }
    cout << endl;
}



int main()
{
    cout << numeric_limits<uint32_t>::max() << endl;
    cout << numeric_limits<uint32_t>::min() << endl;
    cout << numeric_limits<int>::max() << endl;
    cout << numeric_limits<int>::min() << endl;
    bit(43261596);
    Solution s;
    cout << s.reverseBits(4) << endl;
    system("pause");
}