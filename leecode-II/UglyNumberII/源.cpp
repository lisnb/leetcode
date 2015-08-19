#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)
            return -1;
        vector<int> uglynums = { 1 };
        int p2(0), p3(0), p5(0);
        while (n-- > 1)
        {
            int ugly = min({ uglynums[p2] * 2, uglynums[p3] * 3, uglynums[p5] * 5 });
            uglynums.push_back(ugly);
            while (uglynums[p2] * 2 <= ugly)
                ++p2;
            while (uglynums[p3] * 3 <= ugly)
                ++p3;
            while (uglynums[p5] * 5 <= ugly)
                ++p5;
        }
        return uglynums.back();
    }
};