#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int sqrt(int x) {
        if (x <=1)
            return x;
        long long l(1), r(2), t(0), tt(0);
        while (true)
        {
            t = r*r;
            if (t == x)
                return r;
            if (t > x)
                break;
            l = r;
            r<<=1;
        }
        while (r>l+1)
        {
            t = (r + l)>>1;
            tt = t*t;
            if (tt == x)
                return t;
            if (tt > x)
                r = t;
            else
                l = t;
        } 
        return (r+l)/2;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 2,3,4, 9, 16, 625, 1024 };
    for (auto i : test)
    {
        cout << i << "\t" << s.sqrt(i) << endl;
    }
    system("pause");
}