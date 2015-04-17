#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>

using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        auto m = matrix.size();
        if (m == 0)
            return 0;
        auto n = matrix.at(0).size();
        vector<int> row(n, 0);
        int maxa(-1);
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                if (matrix.at(i).at(j) == '1')
                    ++row.at(j);
                else
                    row.at(j) = 0;
            }
            maxa = max(maxa, largestRectangleArea(row));
        }
        return maxa;
    }
private:
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
        int maxa(-1);
        for (auto i = 0; i < len; ++i)
        {
            maxa = max(maxa, height.at(i)*(rights.at(i) - lefts.at(i) + 1));
        }

        return maxa;

    }
};

int main()
{
    Solution s;
    vector<vector<char>> test = {
        { '1', '0', '0', '0', '0', '0' },
        { '1', '1', '0', '1', '1', '1' },
        { '0', '1', '1', '1', '1', '0' },
        { '0', '0', '1', '1', '1', '1' }
    };
    cout << s.maximalRectangle(test) << endl;
    system("pause");
}