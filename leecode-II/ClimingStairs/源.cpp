#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;


class Solution {
public:

    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;
        int cn_1(1), cn_2(0), cn(0);
        for (auto i = 0; i < n; ++i)
        {
            cn = cn_1 + cn_2;
            cn_2 = cn_1;
            cn_1 = cn;
        }
        return cn;
    }

    int climbStairs2(int n) {
        unordered_map<int, int> cache;
        return climb(n, 0, cache);
    }


    int jumpFloorII(int number)
    {
        vector<int> ways(number, 1);
        for (int i = 0; i < number; ++i)
        {
            ways.at(i) = accumulate(ways.begin(), ways.begin() + i+1, 0);
        }
        return ways.back();
    }

private:
    int climb(int n, int cn, unordered_map<int, int> &cache)
    {
        if (cache.find(cn) != cache.end())
            return cache.at(cn);
        if (cn == n)
            return 1;
        if (cn > n)
            return 0;
        int tmp = climb(n, cn + 1, cache) + climb(n, cn + 2, cache);
        cache[cn] = tmp;
        return tmp;
    }



};


int main()
{
    Solution s;
    
    for (auto i = 1; i < 38; ++i)
        //cout << i << " " << s.climbStairs(i)<< "  "<< s.climbStairs2(i)<< endl;
        cout << i << " " << s.jumpFloorII(i) << endl;
    system("pause");
    return 0;
}