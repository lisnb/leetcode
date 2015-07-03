#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        vector<int> cache = { 1, 1 };
        for (int i = 2; i <= n; ++i)
        {
            int tmp(0);
            for (int j = 0; j < i; ++j)
                tmp += cache.at(j - 0) * cache.at(i - j - 1);
            cache.push_back(tmp);
        }
        return cache.back();

    }
};


int main()
{
    Solution s;
    for (auto i = 0; i < 10; ++i)
    {
        cout << i << " " << s.numTrees(i) << endl;
    }
    system("pause");
    return 0;
}