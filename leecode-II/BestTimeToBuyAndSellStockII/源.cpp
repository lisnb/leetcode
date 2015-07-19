#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
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


int main()
{
    Solution s;
    vector<int> test = {8,6};//{ 0, 7, 5, 8, 6, 4, 2, 3 };
    cout << s.maxProfit(test) << endl;
    system("pause");
    return 0;
}