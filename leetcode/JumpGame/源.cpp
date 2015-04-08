#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool canJumpTLE(vector<int> &A, int n) {
        vector<bool> cache(n);
        cache.at(n - 1) = true;
        if (n <= 1)
            return true;
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 1; j <= A.at(i); ++j)
            {
                if (cache.at(i + j))
                {
                    cache.at(i) = true;
                    break;
                }
            }
        }

        return cache.front();
    }

    bool canJump(int A[], int n)
    {
        if (n <= 1)
            return true;
        int maxstep = 0;
        for (int i = 0; i <=maxstep; ++i)
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
};


int main()
{
    Solution s;
    vector<vector<int>> tests = {
        {2,3,1,1,4},
        {3,2,1,0,4}
    };
    for (auto t : tests)
    {
        //cout << s.canJump(t, t.size()) << endl;
    }
    system("pause");
}