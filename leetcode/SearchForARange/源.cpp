#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if (n == 0)
            return{ -1, -1 };
        int start(n), end(-1);
        searchRange(A, n, 0, n - 1, target, start, end);
        return{ start == n ? -1 : start, end };
    }

    void searchRange(int A[], int n, int b, int e, int target, int &start, int &end)
    {
        if (A[b] > target || A[e] < target || b>e )
            return;

        if (A[b] == target && b < start)
            start = b;
        if (A[e] == target && e > end)
            end = e;
        int mid = (b + e) / 2;
        if (A[mid] > target)
        {
            searchRange(A, n, b, mid - 1, target, start, end);
        }
        else if (A[mid] < target)
        {
            searchRange(A, n, mid + 1, e, target, start, end);
        }
        else
        {
            if (mid < start)
                start = mid;
            if (mid > end)
                end = mid;
            if (A[mid-1]>=target)
                searchRange(A, n, b, mid - 1, target, start, end);
            if (A[mid+1]<=target)
                searchRange(A, n, mid + 1, e, target, start, end);
        }

    }

};


int main()
{
    Solution s;
    vector<vector<int>> test = {
        {5, 7, 7, 8,8 ,8,8,8,8,8,8,8,10},
        {1,2,3,4,5},
        {8,8,8,8,8,8,8},
        {8,9,10},
        {5,6,7,8},
        {7,8},
        {8,9},
        {8}
    };
    for (auto t : test)
    {
        int *ta = new int[t.size()];
        for (auto i = 0; i < t.size(); ++i)
        {
            ta[i] = t.at(i);
        }
        vector<int> r = s.searchRange(ta, t.size(), 8);
        cout << "[" << r[0] << ", " << r[1] << "]" << endl;
        delete[] ta;
    }
    system("pause");
}