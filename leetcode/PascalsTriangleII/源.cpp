#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pt(rowIndex + 1, 1);
        int last;
        int tmp;
        for (auto level = 1; level < rowIndex ; ++level)
        {
            last = pt.at(0);
            for (auto position = 1; position < level + 1; ++position)
            {
                tmp = pt.at(position);
                pt.at(position) = last + pt.at(position);
                last = tmp;
            }
        }
        return pt;
    }
};

int main()
{
    Solution s;
    int rowindex = 6;
    for (auto i : s.getRow(rowindex))
    {
        cout << i << " ";
    }
    cout << endl;
    system("pause");
}