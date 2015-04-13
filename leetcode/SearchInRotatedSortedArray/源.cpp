#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    bool search(int A[], int n, int target) {
        return bs(A, 0, n - 1, target);
    }
private:
    bool bs(int A[], int b, int e, int target)
    {
        if (b > e)
            return false;
        if (b == e)
            return A[b] == target;
        int pivot = (b + e) / 2;
        if (A[pivot] == target)
            return true;

        if (A[b] < A[pivot])
        {
            if (target>A[pivot])
                return  bs(A, pivot + 1, e, target);
            else
            {
                if (target == A[b])
                    return true;
                else if (target > A[b])
                    return bs(A, b+1, pivot - 1, target);
                else
                    return bs(A, pivot + 1, e, target);
            }
        }
        else if (A[b] > A[pivot])
        {
            if (target > A[pivot])
            {
                bool lb(false), rb(false);
                if (target == A[e])
                    return true;
                else if (target > A[e])
                    return bs(A, b, pivot - 1, target);
                else
                    return bs(A, pivot + 1, e - 1, target);
            }
            else
                return bs(A, b, pivot - 1, target);
        }
        else
            return bs(A, b, pivot - 1, target) || bs(A, pivot + 1,e , target);
    }

};


int main()
{
    Solution s;
    int num[5] = {1, 3, 1, 1, 1 };
    cout << s.search(num, 5, 3) << endl;
    system("pause");
}