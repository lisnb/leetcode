#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> re;
        if (matrix.empty() || matrix.at(0).empty())
            return re;
        int m(matrix.size()), n(matrix.at(0).size());
        int i = 0;
        while (m > 0 && n > 0)
        {
            spiral(matrix, re, i, m, n);
            ++i;
            m -= 2;
            n -= 2;
        }

        return re;
        

    }
private:
    void spiral(const vector<vector<int>> &matrix, vector<int> &re, int ci, int cm, int cn)
    {
        int cr(ci), cl(ci-1);
        for (int i = 0; i < cn; ++i)
            re.push_back(matrix.at(cr).at(++cl));
        if (cm == 1)
            return;
        for (int i = 0; i < cm-1; ++i)
            re.push_back(matrix.at(++cr).at(cl));
        for (int i = 0; i < cn-1; ++i)
            re.push_back(matrix.at(cr).at(--cl));
        if (cn == 1)
            return;
        for (int i = 0; i < cm-2; ++i)
            re.push_back(matrix.at(--cr).at(cl));
    }
};


int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 }
    };
    vector<vector<int>> matrix2 = { { 2 }, { 3 }, { 4 }, {5} };
    auto re = s.spiralOrder(matrix2);
    for (auto r : re)
        cout << r << " ";
    cout << endl;
    system("pause");
    return 0;
}