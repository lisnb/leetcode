#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0)
            return{};
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int ci = 0, index(1);
        while (n > 0)
        {
            index = spiral(matrix, ci, n, n, index);
            n -= 2;
            ++ci;
        }
        return matrix;
    }
private:
    int spiral(vector<vector<int>> &matrix, int ci, int cm, int cn, int index)
    {
        int cr(ci), cl(ci - 1);
        for (int i = 0; i < cn; ++i)
            matrix.at(cr).at(++cl) = index++;
        if (cm == 1)
            return index;
        for (int i = 0; i < cm - 1; ++i)
            matrix.at(++cr).at(cl)=index++;
        for (int i = 0; i < cn - 1; ++i)
            matrix.at(cr).at(--cl) = index++;
        if (cn == 1)
            return index;
        for (int i = 0; i < cm - 2; ++i)
            matrix.at(--cr).at(cl)=index++;
        return index;
    }
};


int main()
{
    Solution s;
    auto re = s.generateMatrix(2);
    for (auto r : re)
    {
        for (auto rr : r)
            cout << rr << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}