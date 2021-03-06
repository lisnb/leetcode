#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &height)
    {
        int len(height.size());
        if (len == 0)
            return 0;
        if (len == 1)
            return height.at(0);

        stack<int> index;
        vector<int> lefts(len, 0), rights(len, 0);
        int tmp(-1);
        for (auto i = 0; i < len; ++i)
        {
            tmp = i;
            while (!index.empty() && height.at(i) <= height.at(index.top()))
            {
                tmp = lefts[index.top()];
                index.pop();
            }
            lefts.at(i) = tmp;
            index.push(i);
        }

        while (!index.empty())
            index.pop();

        for (int i = len - 1; i >= 0; --i)
        {
            tmp = i;
            while (!index.empty() && height.at(i) <= height.at(index.top()))
            {
                tmp = rights[index.top()];
                index.pop();
            }
            rights.at(i) = tmp;
            index.push(i);
        }
        for (auto l : lefts)
            cout << l << " ";
        cout << endl;
        for (auto r : rights)
            cout << r << " ";
        cout << endl;
        int maxa(-1);
        for (auto i = 0; i < len; ++i)
        {
            maxa = max(maxa, height.at(i)*(rights.at(i) - lefts.at(i) + 1));
        }

        return maxa;

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
        {999,999,999,999},
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