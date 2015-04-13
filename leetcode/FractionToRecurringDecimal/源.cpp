#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream ss;
        if ((numerator > 0) ^ (denominator > 0))
            ss << "-";
        long long lnum = abs((long long)numerator);
        long long lden = abs((long long)denominator);

        long long t = lnum / lden;
        ss << t;
        lnum %= lden;
        if (lnum == 0)
            return ss.str();
        ss << ".";
        unordered_map<long long, string::size_type> cache;
        string s = ss.str();
        cache[lnum] = s.size();
        while (true)
        {
            lnum *= 10;
            ss << lnum / lden;
            lnum %= lden;
            if (lnum == 0)
                return ss.str();
            if (cache.find(lnum) == cache.end())
            {
                cache[lnum] = ss.str().size();
            }
            else
            {
                s = ss.str();
                s.insert(cache[lnum], "(");
                s += ")";
                break;
            }
        }
        return s;
    }
};
  
int main()
{
    Solution s;
    cout << s.fractionToDecimal(-1, -2147483648) << endl;
    return 0;
}