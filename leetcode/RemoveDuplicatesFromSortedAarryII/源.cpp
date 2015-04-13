#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int> A, int n) {
        if (n == 2)
            return 0;
        int curnum(A[0]);
        int cnt(1);
        int p1(0), p2(1);
        while (p2 < n)
        {
            if (A[p2] == curnum)
            {
                ++cnt;
            }
            else
            {
                curnum = A[p2];
                cnt = 1;
            }
            if (cnt < 3)
            {
                A[++p1] = A[p2];
            }
            ++p2;
        }
        return p1;
    }
};


int main()
{
    Solution s;
    vector<int> A = { 1, 1, 1};
    cout << s.removeDuplicates(A, A.size()) << endl;
    system("pause");
}