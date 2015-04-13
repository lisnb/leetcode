#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &height)
    {

    }

    int largestRectangleAreaTLE(vector<int> &height) {
        if (height.size() == 0)
            return 0;
        int b(0), e(height.size() - 1);
        while (b < height.size()&& height.at(b) == 0)
            ++b;
        while (e>=0 && height.at(e) == 0)
            --e;
        if (b > e)
            return 0;
        int maxr(0);
        for (int i = b; i <= e ; ++i)
        {
            if (height.at(i) == 0)
                continue;
            int tmin = height.at(i);
            int tmax(0);
            for (int j = i; j <= e; ++j)
            {
                if (height.at(j) == 0)
                    break;
                if (height.at(j) < tmin)
                    tmin = height.at(j);
                tmax = max(tmax, tmin*(j - i + 1));
            }

            maxr = max(maxr, tmax);
            while (i + 1 <= e && height.at(i) >= height.at(i + 1))
                ++i;
        }
        return maxr;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> tests = {
        {0},
        {2,1,5,6,2,3},
        {3,2,1},
        {2,1,0,5,6,0,3,2}
    };
    for (auto test : tests)
    {
        cout << s.largestRectangleArea(test) << endl;
    }
    system("pause");
}