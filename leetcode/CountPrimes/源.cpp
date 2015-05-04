#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        bool *numbers = new bool[n];
        vector<int> primes;
        for (auto i = 0; i < n; ++i)
            numbers[i] = true;
        int current(1);
        while (current < n-1)
        {
            ++current;
            if (!numbers[current])
            {
                continue;
            }
            primes.push_back(current);
            for (auto i = current; i < n; i += current)
                numbers[i] = false;
        }
        delete []numbers;
        return primes.size();
    }
};

int main()
{
    Solution s;
    vector<int> tests = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    for (auto test:tests)
        cout << s.countPrimes(test) << endl;
    system("pause");
}