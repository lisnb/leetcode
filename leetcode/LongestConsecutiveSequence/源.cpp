#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> cache;
        for (auto n : num)
            cache[n] = false;
        int maxl = 0;
        int t(0);
        for (auto n : num)
        {
            t = findnext(n, cache);
            maxl = max(t, maxl);
        }
        return maxl;
    }
private:
    int findnext(int tn, unordered_map<int, bool> &cache)
    {
        if (cache.find(tn) == cache.end() || cache[tn])
            return 0;
        cache[tn] = true;
        return 1 + findnext(tn - 1, cache) + findnext(tn + 1, cache);
    }
};


int main()
{
    Solution s;

    vector<vector<int>> tests = {
        {100, 4, 200, 1, 3, 2}, 
        {1},
        { 100, 4, 200, 1, 3, 2 ,2},
        { 100, 4, 200, 1, 3, 8 }
    };

    for (auto test : tests)
    {
        cout << s.longestConsecutive(test) << endl;
    }
    system("pause");

}