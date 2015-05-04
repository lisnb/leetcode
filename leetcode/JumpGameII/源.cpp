#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool canJump(int A[], int n)
    {
        if (n <= 1)
            return true;
        int maxstep = 0;
        for (int i = 0; i <= maxstep; ++i)
        {
            if (A[i] + i > maxstep)
            {
                if (A[i] + i >= (n - 1))
                    return true;
                maxstep = A[i] + i;
            }
        }
        return false;
    }

    //[2,3,1,1,4]
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        for (auto i = 0; i < nums.size(); ++i)
            nums.at(i) += i;
        int current(0);
        int step(1);
        while (true)
        {
            if (nums.at(current) >= nums.size() - 1)
                return step;
            int maxstep(0);
            int tcurrent(current + 1);
            for (auto i = current+1; i <= nums.at(current); ++i)
            {
                if (nums.at(i) > maxstep)
                {
                    maxstep = nums.at(i);
                    tcurrent = i;
                }
            }
            current = tcurrent;
            ++step;
            if (current == nums.at(current))
                return 0;
        }
    }

    void qsort(vector<int> &nums)
    {
        int pivot(nums.at(0));
        int p1(-1), p2(0), tmp(0);
        while (p2 < nums.size())
        {
            if (nums.at(p2) < pivot)
            {
                ++p1;
                tmp = nums.at(p1);
                nums.at(p1) = nums.at(p2);
                nums.at(p2) = tmp;
            }
            ++p2;
        }
    }
};


int main()
{
    Solution s;

    /*vector<int> test = { 7, 4, 5, 9, 0, 1, 10 };
    s.qsort(test);
    for (auto t : test)
        cout << t << " ";
    cout << endl;*/
    vector<int> test = { 2, 3, 1, 7, 3, 1, 1, 1, 1, 1,1,1,0,1 };
    cout << s.jump(test) << endl;
    system("pause"); 
}
