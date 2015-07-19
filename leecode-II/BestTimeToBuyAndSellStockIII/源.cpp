#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<=1)
            return 0;
        vector<int> first;
        int minprice = numeric_limits<int>::max();
        int maxprofit = numeric_limits<int>::min();
        for (auto price : prices)
        {
            minprice = min(minprice, price);
            maxprofit = max(maxprofit, price - minprice);
            first.push_back(maxprofit);
        }

        vector<int> second(prices.size(), 0);
        int maxprice = numeric_limits<int>::min();
        maxprofit = numeric_limits<int>::min();

        for (int i = prices.size() - 1; i >= 0; --i)
        {
            maxprice = max(maxprice, prices.at(i));
            maxprofit = max(maxprofit, maxprice - prices.at(i));
            second.at(i)=maxprofit;
        }

        maxprofit = numeric_limits<int>::min();
        for (auto i = 0; i < prices.size(); ++i)
        {
            maxprofit = max(first.at(i) + second.at(i), maxprofit);
        }
        return maxprofit;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 3};
    cout << s.maxProfit(test) << endl;
    system("pause");
    return 0;
}