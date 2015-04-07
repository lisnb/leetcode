#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    unordered_map<int, int> cache;
    int rob(vector<int> &num) {
        cache.clear();
        return robit(num, 0);
    }

    int robit(vector<int> &num, vector<int>::size_type start)
    {
        if (cache.find(start) != cache.end())
            return cache[start];
        if (start >= num.size())
            return 0;
        if (start == num.size() - 1)
            return num.at(start);
        int ln = num.at(start) + robit(num, start + 2);
        int rn = num.at(start + 1) + robit(num, start + 3);
        int bigger = ln > rn ? ln : rn;
        cache[start] = bigger;
        return bigger;
    }

    int robit2(vector<int> &num)
    {
        return 0;
    }
};




int main()
{
    vector<vector<int>> tests = {
        {7,3,5,8,9,20,4}
    };
    Solution s;
    for (auto t : tests)
    {
        cout << s.rob(t) << endl;
    }
    system("pause"); 
}