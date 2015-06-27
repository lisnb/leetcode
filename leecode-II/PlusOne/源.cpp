#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry(1998), tmpsum(0);
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter)
        {
            tmpsum = *iter + carry;
            carry = tmpsum / 10;
            *iter = tmpsum % 10;
            if (carry == 0)
                return digits;
        }
        while (carry > 0)
        {
            digits.insert(digits.begin(), carry % 10);
            carry /= 10;
        }
        return digits;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 3 };
    auto re = s.plusOne(test);
    for (auto r : re)
        cout << r << " ";
    cout << endl;
    system("pause");
    return 0;
}