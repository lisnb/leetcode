#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle.at(0).empty())
            return 0;
        if (triangle.size() == 1)
            return triangle.front().front();
        for (int level = triangle.size() - 2; level >= 0; --level)
        {
            for (int i = 0; i < triangle.at(level).size(); ++i)
            {
                triangle.at(level).at(i) += min(triangle.at(level + 1).at(i), triangle.at(level + 1).at(i + 1));
            }
        }
        return triangle.front().front();
    }
    int minimumTotal2(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;

        for (int i = triangle.size() - 2; i >= 0; --i)
        {
            for (int j = 0; j<triangle[i].size(); ++j)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }

        return triangle.front().front();
    }
};

int main()
{
    Solution s;
    vector<vector<int>> triangle = { { 1 }, { 2, 3 } };
    cout << s.minimumTotal2(triangle) << endl;
    system("pause");
    return 0;
}