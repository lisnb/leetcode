#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;


class Solution {
public:

    int movintCount2(int threshold, int rows, int cols)
    {
        if ((cols == 0 && rows == 0) || threshold <0)
            return 0;
        if (threshold == 0)
            return 1;
        if (calsum(rows - 1, cols - 1) <= threshold)
            return rows*cols;
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        for (auto i = 0; i < rows; ++i)
            matrix.at(i).at(0) = calsum(i, 0) <= threshold ? 1 : 2;
        for (auto j = 0; j < cols; ++j)
            matrix.at(0).at(j) = calsum(0, j) <= threshold ? 1 : 2;

        for (auto i = 1; i < rows; ++i)
        {
            for (auto j = 1; j < cols; ++j)
            {

            }
        }
    }
    int movingCount(int threshold, int rows, int cols)
    {
        if ((cols == 0 && rows == 0) || threshold <0)
            return 0;
        if (threshold == 0)
            return 1;
        if (calsum(rows - 1, cols - 1) <= threshold)
            return rows*cols;
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        matrix.front().front() = 1;
        deque<pair<int, int>> queue;
        queue.push_back(make_pair(0, 0));
        int cnt(0);
        while (!queue.empty())
        {
            ++cnt;
            auto current = queue.front();
            int row(current.first), col(current.second);
            cout << row << " " << col << endl;
            queue.pop_front();

            if (row + 1 != rows&&matrix.at(row + 1).at(col) == 0)
            {
                if (calsum(row + 1, col) > threshold)
                    matrix.at(row + 1).at(col) = 2;
                else
                {
                    matrix.at(row + 1).at(col) = 1;
                    queue.push_back(make_pair(row + 1, col));
                }
            }
            if (row - 1 != -1 && matrix.at(row - 1).at(col) == 0)
            {
                if (calsum(row - 1, col) > threshold)
                    matrix.at(row - 1).at(col) = 2;
                else
                {
                    matrix.at(row - 1).at(col) = 1;
                    queue.push_back(make_pair(row - 1, col));
                }

            }
            if (col + 1 != cols && matrix.at(row).at(col + 1) == 0)
            {
                if (calsum(row, col + 1) > threshold)
                    matrix.at(row).at(col + 1) = 2;
                else
                {
                    matrix.at(row).at(col + 1) = 1;
                    queue.push_back(make_pair(row, col + 1));
                }

            }
            if (col - 1 != -1 && matrix.at(row).at(col - 1) == 0)
            {
                if (calsum(row, col - 1) > threshold)
                    matrix.at(row).at(col - 1) = 2;
                else
                {
                    matrix.at(row).at(col - 1) = 1;
                    queue.push_back(make_pair(row, col - 1));
                }
            }
        }

        for (auto therow : matrix)
        {
            for (auto thecol : therow)
                cout << thecol << " ";
            cout << endl;
        }
        cout << endl;

        return cnt;
    }

private:
    int calsum(int row, int col)
    {
        int sum(0);
        while (row != 0 || col != 0)
        {
            sum += (row % 10 + col % 10);
            row /= 10;
            col /= 10;
        }
        return sum;
    }
};



int main()
{
    Solution s;
    cout << s.movingCount(10, 10, 10) << endl;
    system("pause");
    return 0;
}