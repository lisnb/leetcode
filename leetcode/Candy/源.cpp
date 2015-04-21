#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings)
    {
        if (ratings.size() <= 1)
            return ratings.size();
        vector<int> cans(ratings.size(), 1);
        for (auto i = 1; i < ratings.size(); ++i)
            if (ratings.at(i)>ratings.at(i - 1))
                cans.at(i) = cans.at(i - 1) + 1;
        for (int i = ratings.size() - 2; i >= 0; --i)
            if (ratings.at(i) > ratings.at(i + 1) && cans.at(i) <= cans.at(i + 1))
                cans.at(i) = cans.at(i + 1) + 1;
        int total(0);
        for each (auto  i in cans)
        {
            total += i;
        }
        return total;

    }
    int candyWA(vector<int> &ratings) {
        if (ratings.size() <= 1)
            return ratings.size();
        int i = 0;
        while (i +1< ratings.size() && ratings.at(i+1) <= ratings.at(i))
            ++i;

        int total = 1;
        int last = 1;
        for (int j = i-1; j >= 0; --j)
        {
            if (ratings.at(j) > ratings.at(j + 1))
                last += 1;
            else
                last = 1;
            total += last;
        }
        last = 1;
        for (auto j = i+1 ; j < ratings.size(); ++j)
        {
            if (ratings.at(j)>ratings.at(j - 1))
            {
                last += 1;
            }
            else 
            {
                last = 1;
            }
            total += last;
        }
        return total;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> tests = {
        {2,2,2,2},
        {2,2,1},
        {1,2,2},
        {3,2,1,2,3},
        {1,5,6,3,8,9,1},
        {1,2,3,4,5,6,7,8},
        {9,8,7,6,5,4,3,2,1},
        {1,3,2,4,6,5,8,7,9}
    };

    for (auto test : tests)
        cout << s.candy(test) << endl;

    system("pause");
}