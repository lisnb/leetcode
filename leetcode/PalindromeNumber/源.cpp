#include <iostream>
using namespace std;



class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long pac = 10;
        int t = x;
        while (t/pac > 0)
        {
            pac *= 10;
        }
        pac /= 10;
        cout << pac << endl;
        long frac = 1;
        while (frac< pac)
        {
            int l = (x % (pac * 10)) / pac;
            int r = (x % (frac * 10)) / frac;
            cout << l << "  " << r << endl;
            if (l != r)
                return false;
            frac *= 10;
            pac /= 10;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome(102) << endl;
    //return 0;
    system("pause");
}


