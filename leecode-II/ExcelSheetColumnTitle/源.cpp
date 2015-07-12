#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


/*
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
*/


class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0)
            return "";
        stringstream ss;
        while (n > 0)
        {
            int tmp = (n-1) % 26;
            ss << (char)('A' + tmp);
            n = (n-1) /26;
        }
        string re = ss.str();
        reverse(re.begin(), re.end());
        return re;
    }
};


int main()
{
    Solution s;
    for (auto i = 0; i < 26*30; ++i)
        cout << i << " " << s.convertToTitle(i) << endl;
    system("pause");
    return 0;
}