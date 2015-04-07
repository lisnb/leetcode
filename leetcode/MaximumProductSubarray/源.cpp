#include <iostream>
#include <unordered_map>

using namespace std;




class Solution {
    struct ninfo{
        int maxpos;
        int maxneg;
    };
public:
    int maxProduct(int A[], int n) {
        if (n == 1)
            return A[0];
        int maxpos(0), maxneg(0), max(INT_MIN), tp(0), tn(0);
        for (auto i = n - 1; i >= 0; --i)
        {
            tp = A[i] * maxpos;
            tn = A[i] * maxneg;
            if (tn>tp)
                swap(tn, tp);
            if (tp>max)
                max = tp;
            if (A[i]>max)
                max = A[i];
            maxpos = tp>A[i] ? tp : A[i];
            maxneg = tn<A[i] ? tn : A[i];
        }
        return max;
    }

    int maxPro2(int A[], int n)
    {
        int maxpro(INT_MIN);
        int maxneg(INT_MAX);
        return 0;

    }

    int maxPro(int A[], int n){
        ninfo start = { 0, 0 };
        int max(INT_MIN);
        for (auto i = n - 1; i >= 0; --i)
        {
            if (A[i] > 0)
            {
                int t = A[i] * start.maxpos;
                start.maxpos = A[i] > t ? A[i] : t;
                start.maxneg *= A[i];
                
            }
            else if(A[i] < 0)
            {
                int t = A[i] * start.maxneg;
                if (t>start.maxpos)
                    start.maxpos = t;
                start.maxneg = start.maxpos * A[i];
            }
            else
            {
                start.maxpos = 0;
                start.maxneg = 0;
            }

            if (start.maxpos > max)
                max = start.maxpos;
        }
        return max;
    }
private:
    unordered_map<int, int> cache;
    
};


int main()
{
    Solution s;
    //vector<int> test = { 2, 3, -2, 4 };
    int test[4] = { 2, 3, -2, 4 };
    cout << s.maxProduct(test, 4)<<endl;
    system("pause");
}