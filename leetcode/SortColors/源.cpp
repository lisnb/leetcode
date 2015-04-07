#include <vector>
#include <iostream>

using namespace std;




class Solution {
public:
    void sortColors(int A[], int n) {
        // two passes
        // first, 00000012121212
        // second, 00000011112222
        if (n <= 1)
            return;
        int p0b(-1);
        while (p0b + 1 < n && A[p0b+1] == 0)
            ++p0b;
        int p12b(p0b + 1);
        int t(0);
        while (p12b < n)
        {
            if (A[p12b] > 0)
            {
                ++p12b;
                continue;
            }
            else
            {
                ++p0b;
                A[p12b] = A[p0b];
                A[p0b] = 0;
            }
        }
        while (p0b + 1 < n && A[p0b + 1] == 1)
            ++p0b;
        p12b = p0b + 1;
        while (p12b < n)
        {
            if (A[p12b] > 1)
            {
                ++p12b;
                continue;
            }
            else
            {
                ++p0b;
                A[p12b] = A[p0b];
                A[p0b] = 1;
            }
        }
    }
};


int main()
{
    Solution s;
    //int test[15] = { 0, 1, 2, 0, 0, 1, 1, 2, 2, 1, 2, 0, 2, 2, 1 };
    int test[15] = { 2,2,2,2,2,1,1,1,1,1,1,0,0,0,0};

    s.sortColors(test, 15);

    for (auto i : test)
    {
        cout << i << " ";
    }
    cout << endl;
    system("pause");
}