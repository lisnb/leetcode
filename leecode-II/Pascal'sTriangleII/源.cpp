#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return{ 1 };
        vector<int> row(rowIndex + 1, 1);
        int last(0), tmp(0);
        for (auto i = 0; i <= rowIndex; ++i)
        {
            last = row.at(0);
            for (auto j = 1; j < i; ++j)
            {
                tmp = row.at(j);
                row.at(j) += last;
                last = tmp;
            }
        }

        return row;
    }
};

int main()
{
    Solution s;
    auto re = s.getRow(5);
    for (auto r : re)
        cout << r << " ";
    cout << endl;
    system("pause");
    return 0;

}