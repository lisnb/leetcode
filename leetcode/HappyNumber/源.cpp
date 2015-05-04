#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0)
            return false;
        unordered_set<int> cache;
        int tsum(0);
        while (true)
        {
            tsum = getsquare(n);
            if (tsum == 1)
                return true;
            if (cache.find(tsum) != cache.end())
                return false;
            cache.insert(tsum);
            n = tsum;
        }
    }

private:
    int getsquare(int n)
    {
        int sum(0), t(0);
        while (n > 0)
        {
            t = n % 10;
            sum += t*t;
            n /= 10;
        }
        return sum;
    }
};


int main()
{
    Solution s;
    vector<int> tests = {
        1,
        19,
        28,
        981
    };
    for (auto test : tests)
        cout << test << " " << s.isHappy(test) << endl;

    system("pause");
}
