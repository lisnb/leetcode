#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        return countDigit(n, 1);
    }

private:
    int countDigit(int n, int digit)
    {
        if (n < digit)
            return 0;
        if (n == digit)
            return 1;
        long long frac = 1;
        while (n / (frac * 10) > 0)
            frac *= 10;
        int cnt(0);
        while (frac > 0)
        {
            int currentdigit = (n%(frac*10)) / frac;
            if (currentdigit < digit)
            {
                cnt += (n / (frac * 10))*frac;
            }
            else if (currentdigit > digit)
            {
                cnt += (n / (frac * 10) + 1)*frac;
            }
            else
            {
                cnt += (n / (frac * 10))*frac + n%frac + 1;
            }
            frac /= 10;
        }
        return cnt;
    }       
};


int main()
{
    Solution s;
    vector<int> test = { 1410065408, 2328, 13, 18, 1111 };
    for (auto t : test)
        cout << t << " " << s.countDigitOne(t) << endl;
    system("pause");
    return 0;
}