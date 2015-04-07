#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int b(0), nre(0), nt(0), re(0);
        int min(INT_MAX);
        while (b + 2 < num.size())
        {
            nt = target - num.at(b);
            nre = twoSumClosest(num, b + 1, nt);
            if (abs(nt - nre) < min)
            {
                re = num.at(b) + nre;
                min = abs(nt-nre);
            }
            ++b;
        }
        return re;
    }

    int twoSumClosest(vector<int> &num, int b, int target){
        int e = num.size() - 1;
        int min(INT_MAX);
        int tm(0);
        int re(0);
        while (b < e)
        {
            tm = target - num.at(b) - num.at(e);
            if (tm == 0)
                return target;
            if (tm > 0)
                ++b;
            if (tm < 0)
                --e;
            if (abs(tm) < min)
            {
                re = target - tm;
                min = abs(tm);
            }
        }
        return re;
    }
};


int main()
{
    Solution s;

    vector<vector<int> > test = {
        //{ -1, 2, 1, 4 },
        {1,1,1,4,7,3,5,7,9,2}
    };

    for (auto t : test)
    {
        for (auto tt : t)
        {
            cout << tt << " ";
        }
        cout << "\t" << s.threeSumClosest(t, 100) << endl;
    }

    system("pause");
}