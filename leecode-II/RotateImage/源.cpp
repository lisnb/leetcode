#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() <= 1)
            return;
        int n(matrix.size()), cn(0);
        for (int i = 0; i < n/2; ++i)
        {
            cn = n - i * 2;
            for (int j = 0; j < cn - 1; ++j)
            {
                int cr(i), cl(i+j), ncr(0), ncl(0);
                int tmp(matrix.at(cr).at(cl));
                for (int k=0;k<3;++k)
                {
                    //int ncr(n-1-cl), ncl(cr);
                    ncr = n - 1 - cl;
                    ncl = cr;
                    matrix.at(cr).at(cl) = matrix.at(ncr).at(ncl);
                    cr = ncr;
                    cl = ncl;
                }
                matrix.at(i+j).at(n - 1 - i) = tmp;
            }
        }
    }
};


int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    vector<vector<int>> matrix2 = { { 1, 2 }, { 4, 5}};
    s.rotate(matrix2);
    return 0;
}