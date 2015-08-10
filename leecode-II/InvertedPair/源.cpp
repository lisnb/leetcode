#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution{

public:
    int inversePair(vector<int> nums)
    {
        if (nums.size()<=1)
            return 0;

        return merge(nums, 0, nums.size() - 1);
    }

private:
    int merge(vector<int> &nums, int b, int e)
    {
        if (b == e)
            return 0;
        else
        {
            int mid = b + (e - b) / 2;
            int lip = merge(nums, b, mid);
            int rip = merge(nums, mid + 1, e);

            int ip(0);
            int rindex(e - b), i1(mid), i2(e);
            vector<int> temp(e - b + 1, 0);
            while (i1>=b && i2>mid)
            {
                if (nums.at(i1) > nums.at(i2))
                {
                    temp.at(rindex--) = nums.at(i1--);
                    ip += (i2 - mid);
                }
                else
                {
                    temp.at(rindex--) = nums.at(i2--);
                }
            }
            if (i1 == b-1)
            {
                while (i2 > mid)
                    temp.at(rindex--) = nums.at(i2--);
            }
            else
            {
                while (i1 >= b)
                    temp.at(rindex--) = nums.at(i1--);
            }
            copy(temp.begin(), temp.end(), nums.begin() + b);
            return lip + rip + ip;
        }
    }
};

int main()
{
    Solution s;
    vector<int> test = { 8, 7 };
    cout << s.inversePair(test) << endl;
    system("pause");
    return 0;
}