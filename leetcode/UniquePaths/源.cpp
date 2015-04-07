#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> level(n, 1);
        for (auto i = 1; i < m; ++i)
        {
            for (auto j = 1; j < n; ++j)
                level.at(j) += level.at(j - 1);
        }
        return level.back();
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3, 5) << endl;
    system("pause");
}