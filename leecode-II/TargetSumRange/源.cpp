#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if (sum < 2)
            return{};
        int b(1), e(2), tsum(3);
        vector<vector<int>> re;
        while (e <= sum / 2 + 1)
        {
            if (tsum == sum)
            {
                vector<int> tvec;
                for (auto i = b; i <= e; ++i)
                    tvec.push_back(i);
                re.push_back(tvec);
                tsum -= b;
                ++b;
            }
            else if (tsum > sum)
            {
                tsum -= b;
                ++b;
            }
            else
            {
                ++e;
                tsum += e;
            }
        }
        return re;
    }
};

int main()
{
    Solution s;
    auto re = s.FindContinuousSequence(5);
    for (auto r : re)
    {
        for (auto rr : r)
            cout << rr << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}