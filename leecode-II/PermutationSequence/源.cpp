#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;



class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1)
            return "1";
        vector<int> factorial(n+1, 1);
        for (int i = 1; i <= n; ++i)
            factorial.at(i) = factorial.at(i - 1)*i;

        k %= factorial.back();
        stringstream ss;
        vector<int> flags(n, 1);
        int tmp(-1);
        while (n-- > 0)
        {
            tmp = k/factorial.at(n);
            k %= factorial.at(n);
            for (auto i = 0; i < flags.size(); ++i)
            {
                if (flags.at(i) == -1)
                    continue;
                --tmp;
                if (tmp == -1)
                {
                    flags.at(i) = -1;
                    ss << (i+1);
                }
            }
        }

        return ss.str();

    }
};

int main()
{
    Solution s;
    for (auto i = 0; i < 16;++i)
        cout << s.getPermutation(4, i) << endl;
    system("pause"); 
    return 0;
}