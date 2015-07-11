#include <iostream>

using namespace std;




class Solution {
public:
    double myPow(double x, int n) {
        bool negative(false);
        if (n < 0)
        {
            negative = true;
            n = -n;
        }
        double r(1);
        while (n > 0)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return negative?1/r:r;
    }
};


int main()
{
    Solution s;
    for (int i = -5; i < 20; ++i)
        cout << i << " " << s.myPow(2, i) << endl;
    system("pause");
    return 0;

}