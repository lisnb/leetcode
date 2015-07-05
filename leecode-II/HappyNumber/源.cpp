#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cache;
        while (true)
        {
            int tmp = happy(n);
            if (tmp == 1)
                return true;
            if (cache.find(tmp) != cache.end())
                return false;
            cache.insert(tmp);
            n = tmp;
        }
        return false;
    }

private:
    int happy(int n)
    {
        if (n == 1)
            return 1;
        int sum(0), tmp(0);
        while (n > 0)
        {
            tmp = n % 10;
            sum += tmp*tmp;
            n /= 10;
        }
        return sum;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 19, 28, 82, 68, 100 };
    for (auto t : test)
        cout << t << " " << s.isHappy(t) << endl;
    system("pause");
    return 0;
}