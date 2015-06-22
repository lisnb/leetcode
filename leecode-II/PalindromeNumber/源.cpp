#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;






class Solution {
public:
    bool isPalindrome(int x) {
        if (x<10 && x>-10)
            return true;
        long long number = x;
        if (number < 0)
            number = -number;
        long long fraction = 10;
        while (number/fraction>0)
            fraction *= 10;
        fraction /= 10;
        int front(0), tail(0);
        while (number > 0)
        {
            tail = number % 10;
            front = number / fraction;
            if (tail != front)
                return false;
            number = (number%fraction) / 10;
            fraction /= 100;
        }
        return true;
    }
};


int main()
{
    Solution s;
    vector<int> test = { numeric_limits<int>::min(), 0, 12321, 123321, -12 };
    for (auto t : test)
        cout << t << " " << s.isPalindrome(t) << endl;
    system("pause");
    return 0;
}