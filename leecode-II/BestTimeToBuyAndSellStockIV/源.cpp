#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.empty())
            return 0;
        if (k >= prices.size() / 2)
            return maxProfit(prices);
        vector<int> balance(k + 1, numeric_limits<int>::min()), profit(k + 1);
        for (int i = 0; i < prices.size(); ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                balance[j] = max(profit[j - 1] - prices[i], balance[j]);
                profit[j] = max(profit[j], balance[j] + prices[i]);
            }
        }
        return profit[k];
    }
private:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices.at(i)>prices.at(i - 1))
                profit += (prices.at(i) - prices.at(i - 1));
        }
        return profit;
    }
};

