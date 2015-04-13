#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> forwards(prices.size(), 0);
        vector<int> backwards(forwards);

        int minx = prices[0];

        for (auto i = 1; i < prices.size(); ++i)
        {
            minx = min(minx, prices.at(i));
            forwards.at(i) = max(forwards.at(i - 1), prices.at(i) - minx);
        }

        int maxx = prices.back();
        for (int i = prices.size() - 2; i >= 0; --i)
        {
            maxx = max(maxx, prices.at(i));
            backwards.at(i) = max(backwards.at(i + 1), maxx - prices.at(i));
        }

        int ret = 0;
        for (auto i = 0; i < prices.size(); ++i)
        {
            ret = max(ret, forwards.at(i) + backwards.at(i));
        }

        return ret;

    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2  };
    cout << s.maxProfit(test) << endl;
    system("pause");
}