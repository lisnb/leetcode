#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for (int level = triangle.size() - 2; level >= 0; --level)
        {
            for (auto i = 0; i < triangle.at(level).size(); ++i)
            {
                triangle.at(level).at(i) += min(triangle.at(level + 1).at(i), triangle.at(level + 1).at(i + 1));
            }
        }
        return triangle.at(0).at(0);
    }
};

int main()
{
    Solution s;
    return 0;
}