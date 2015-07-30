#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        if (ratings.size() <= 1)
            return ratings.size();
        vector<int> candies( ratings.size(), 1);
        for (auto r : ratings)
            cout << r << " ";
        cout << endl;
        for (auto i = 1; i < ratings.size(); ++i)
        {
            if (ratings.at(i)>ratings.at(i - 1))
                candies.at(i) = candies.at(i - 1) + 1;
        }
        for (auto c : candies)
            cout << c << " ";
        cout << endl;
        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings.at(i) > ratings.at(i + 1))
                candies.at(i) = max(candies.at(i),candies.at(i + 1) + 1);
            //else if (ratings.at(i) == ratings.at(i + 1))
                //candies.at(i) = max(candies.at(i), candies.at(i + 1));
        }

        
        for (auto c : candies)
            cout << c << " ";
        cout << endl;

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main()
{
    Solution s;
    vector<int> test = { 8, 8, 8, 8, 7, 6, 6, 6, 9, 4, 5, 2, 4, 8, 1, 100 };
    cout << s.candy(test) << endl;
    system("pause");
    return 0;
}