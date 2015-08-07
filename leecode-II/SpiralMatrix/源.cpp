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

    void spiral(const vector<vector<int>> &matrix, vector<int> &re, int ulx, int uly, int drx, int dry)
    {
        int i(ulx), j(uly);
        while (j <= dry)
            re.push_back(matrix.at(i).at(j++));
        --j;
        ++i;
        while (i <= drx)
            re.push_back(matrix.at(i++).at(j));
        --i;
        --j;
        while (j >= uly)
            re.push_back(matrix.at(i).at(j--));
        ++j;
        --i;
        while (i>ulx)
            re.push_back(matrix.at(i--).at(j));
    }
};


class Solution2 {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty())
            return{};
        if (matrix.front().empty())
            return{};
        vector<int> re;
        int r(matrix.size() - 1), c(matrix.front().size() - 1);
        int ulx(0), uly(0), drx(r), dry(c);
        while (ulx <= drx&&uly <= dry)
        {
            spiral(matrix, re, ulx, uly, drx, dry);
            ++ulx;
            ++uly;
            --drx;
            --dry;
        }
        return re;
    }

    void spiral(const vector<vector<int>> &matrix, vector<int> &re, int ulx, int uly, int drx, int dry)
    {
        int i(ulx), j(uly);
        while (j <= dry)
            re.push_back(matrix.at(i).at(j++));
        --j;
        ++i;
        if (ulx == drx)
            return;
        while (i <= drx)
            re.push_back(matrix.at(i++).at(j));
        --i;
        --j;
        if (uly == dry)
            return;
        while (j >= uly)
            re.push_back(matrix.at(i).at(j--));
        ++j;
        --i;
        while (i>ulx)
            re.push_back(matrix.at(i--).at(j));
    }

};


int main()
{
    Solution2 s;
    vector<vector<int>> matrix = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 }
    };
    vector<vector<int>> matrix2 = { { 2 }, { 3 }, { 4 }, {5} };
    vector<vector<int>> matrix3 = { { 1, 2, 3, 4 } };
    //auto re = s.spiralOrder(matrix2);
    auto re = s.printMatrix(matrix3);
    for (auto r : re)
        cout << r << " ";
    cout << endl;
    system("pause");
    return 0;
}