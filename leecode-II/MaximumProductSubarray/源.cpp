#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;


class Solution {
public:
    int maxProduct3(vector<int>& nums) {
        int mp(numeric_limits<int>::min()), np(numeric_limits<int>::max()), cmp(numeric_limits<int>::min()), cnp(numeric_limits<int>::max());
        
        for (auto n : nums)
        {
            if (n == 0)
            {
                cmp = 0;// numeric_limits<int>::min();
                cnp = 0;// numeric_limits<int>::max();
                mp = max(cmp, mp);
            }
            else if (n > 0)
            {

                cnp = cnp == numeric_limits<int>::max() ? n : cnp*n;
                cmp = cmp == numeric_limits<int>::min() ? n : cmp*n;

                np = min(np, cnp);
                mp = max(mp, cmp);
            }
            else
            {
                int tmp = cnp;
                cnp = cnp == numeric_limits<int>::max() ? n : cmp*n;
                cmp = cmp == numeric_limits<int>::min() ? numeric_limits<int>::min() : tmp*n;
                np = min(np, cnp);
                mp = max(mp, cmp);
            }

        }

        return mp < 0 ? np : mp;
    }

    int maxProduct(vector<int>& nums) {
        int mp(numeric_limits<int>::min()), np(numeric_limits<int>::max()), mmp(numeric_limits<int>::min());
        int cmp(0), cnp(0);
        bool haszero = false;
        for (auto n : nums)
        {

            if (n == 0)
            {
                haszero = true;
                cmp = 0;
                cnp = 0;
            }
            else if (n > 0)
            {
                if (cnp == 0 && cmp == 0)
                    cmp = n;
                else if (cnp == 0)
                    cmp *= n;
                else if (cmp == 0)
                {
                    cnp *= n;
                    cmp = n;
                }
                else
                {
                    cnp *= n;
                    cmp *= n;
                }
            }
            else
            {
                mmp = max(mmp, n);
                if (cnp == 0 && cmp == 0)
                    cnp = n;
                else if (cnp == 0)
                {
                    cnp = cmp*n;
                    cmp = 0;
                }
                else if (cmp == 0)
                {
                    cmp = cnp*n;
                    cnp = n;
                }
                else
                {
                    int tmp = cnp;
                    cnp = cmp*n;
                    cmp = tmp*n;
                }
            }

            np = min(np, cnp);
            mp = max(mp, cmp);

        }

        return mp == 0?(haszero?0:mmp):mp;
    }


    int maxProduct2(vector<int>& nums)
    {
        int cmp(nums.at(0)), cnp(nums.at(0)), mp(nums.at(0));
        for (auto i = 1; i < nums.size(); ++i)
        {
            int tmp = cmp;
            cmp = max({ cmp, nums.at(i)*cmp, nums.at(i)*cnp });
            cnp = min({ cnp, nums.at(i)*tmp, nums.at(i)*cnp });
            mp = max({ cmp, cnp, mp });
        }
        return mp;
    }
};

int main()
{
    Solution s;
    vector<int> test = {7, -2, -4};
    auto r = s.maxProduct2(test);
    cout << r << endl;
    system("pause");
    cout << r;
}