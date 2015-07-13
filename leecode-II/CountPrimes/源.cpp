#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        bool *nums = new bool[n];
        for (auto i = 0; i < n; ++i)
            nums[i] = true;
        for (int i = 2; i*i < n; ++i)
        {
            if (!nums[i]) continue;
            for (int j = i*i; j < n; j += i)
                nums[j] = false;
        }
        int cnt(0);
        for (int i = 2; i < n;++i)
            if (nums[i])
            {
                cout << i << endl;
                ++cnt;
            }
        delete[]nums;
        return cnt;
    }
};

int main()
{
    Solution s;
    cout << s.countPrimes(10) << endl;
    system("pause");
    return 0;
}