#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            swap(a, b);
        if (b.empty())
            return a;
        int pa(a.size() - 1), pb(b.size() - 1);
        int carry(0), tmpsum(0);
        stringstream ss;
        while (pb >= 0)
        {
            tmpsum = carry + a.at(pa) + b.at(pb) - 2 * '0';
            ss << (tmpsum % 2);
            carry = tmpsum / 2;
            --pa;
            --pb;
        }
        while (pa >= 0)
        {
            tmpsum = carry + a.at(pa) - '0';
            ss << (tmpsum % 2);
            carry = tmpsum / 2;
            --pa;
        }
        while (carry > 0)
        {
            ss << (carry % 2);
            carry /= 2;
        }
        string re = ss.str();
        reverse(re.begin(), re.end());
        return re;
    }
};


int main(){
    Solution s;
    string a("0"), b("1");
    cout << s.addBinary(a, b) << endl;
    system("pause");
    return 0;
}