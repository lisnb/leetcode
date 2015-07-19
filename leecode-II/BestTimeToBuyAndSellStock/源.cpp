#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int minprice = numeric_limits<int>::max();
        int maxprofit = numeric_limits<int>::min();
        for (auto price : prices)
        {
            if (price < minprice)
                minprice = price;
            maxprofit = max(maxprofit, price - minprice);
        }
        return maxprofit;

    }
};