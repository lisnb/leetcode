#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> re;
        if (n == 0)
            return re;
        for (auto i = 0; i < n; ++i)
            re.push_back(vector<int>(n, 0));
        int start = 1;
        for (auto i = 0; i < n/2; ++i)
        {
            start = fill(re, start, i, n - 2 * i);
        }
        if (n % 2 == 1)
            re.at(n / 2).at(n / 2) = n*n;
        return re;
    }

private:
    int  fill(vector<vector<int>> &matrix, int start, int row, int n)
    {
        for (auto i = row ; i < row + n ; ++i)
        {
            matrix.at(row).at(i) = start++;
        }
        for (auto i = row+1; i < row + n; ++i)
        {
            matrix.at(i).at(row + n - 1) = start++;
        }
        for (auto i = row + n - 2; i >= row; --i)
        {
            matrix.at(row + n - 1).at(i) = start++;
        }
        for (auto i = row + n - 2; i > row; --i)
        {
            matrix.at(i).at(row) = start++;
        }
        return start;
    }
};


int main()
{
    Solution s;

    auto re = s.generateMatrix(6);
    for (auto i : re)
    {
        for (auto ii : i)
        {
            cout << ii << " ";
        }
        cout << endl;
    }
    system("pause");

}