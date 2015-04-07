#include <iostream>
#include <vector>
#include <limits>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        //cout << "long max" << numeric_limits<long>::max() << endl;
        int np = x < 0 ? -1 : 1;
        int px = x*np;
        long long nx = px;
        cout <<"nx: "<< nx << endl;
        vector<short> digits;
        int fac = 10;
        while (nx>0)
        {
            digits.push_back(nx%fac);
            nx /= fac;
        }
        long long rx = 0;
        
        for (vector<short>::const_iterator di = digits.cbegin(); di != digits.cend(); ++di)
        {
            rx = rx*fac + *di;
        }
        cout << "rx: " << rx << endl;
        if (rx > numeric_limits<int>::max())
        {
            return 0;
        }
        cout << x << "\t" << ((int)rx)*np << endl;
        return ((int)rx)*np; 
    }
};

int main()
{
    Solution s;
    vector<int> tests = { 123, -123, 1000, 100, 1, 0, 1000000003 };
    for (auto t : tests)
    {
        s.reverse(t);
        //cout << t << "\t" << s.reverse(t) << endl;
    }
    system("pause");
}