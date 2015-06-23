#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> re;
        if (n == 0)
            return re;
        string prefix("");
        generate(re, 0, 0, 2 * n, prefix);
        return re;
    }
private:
    void generate(vector<string> &re, int lc, int rc, int n, string &prefix)
    {
        if (rc > lc || lc>n/2)
            return;
        if (lc + rc == n)
        {
            //if (lc==rc)
                re.push_back(prefix);
            return;
        }
        prefix.push_back('(');
        generate(re, lc + 1, rc, n, prefix);
        prefix.pop_back();

        prefix.push_back(')');
        generate(re, lc, rc + 1, n, prefix);
        prefix.pop_back();
    }
};


int main()
{
    Solution s;
    int test(3);
    auto re = s.generateParenthesis(test);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}