#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cinttypes>

using namespace std;



class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0 || n == 0xffffffff)
            return n;
        uint32_t nn(0);
        uint32_t mask1(1), mask2(0x1<<31);

        for (auto leftshift = 0; leftshift < 32;++leftshift)
        {
            uint32_t tmpmask1 = mask1 << leftshift;
            uint32_t tmpmask2 = mask2 >> leftshift;
            if ((n&tmpmask1) != 0)
            {
                nn |= tmpmask2;
            }
        }
        return nn;
    }
};


int main()
{
    Solution s;
    cout << (0x1 << 31) << endl;
    vector<uint32_t> test = {
        43261596,
        1,
        0,
    };
    for (auto t : test)
        cout << t << " " << s.reverseBits(t) << endl;
    system("pause");
    return 0;
}