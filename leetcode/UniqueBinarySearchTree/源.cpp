#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;


class Solution {
public:
    int numTrees(int n) {
        if (n == 0)
            return 0;
        vector<int> tcnt = { 1, 1, 2, 5 };
        if (n <= 3)
            return tcnt.at(n);
        for (auto i = 4; i <=n; ++i)
        {
            int cnt = 0;
            for (auto j = 0; j < i / 2; ++j)
            {
                cnt += (tcnt.at(j) * tcnt.at(i - j - 1));
            }
            cnt *= 2;
            if (i % 2 == 1)
                cnt += (tcnt.at(i / 2)*tcnt.at(i / 2));
            tcnt.push_back(cnt);
        }
        return tcnt.at(n);
    }
};

int main()
{
    Solution s;
    //for (auto i = 1; i < 6;++i)
        cout << s.numTrees(5) << endl;
    system("pause");
}