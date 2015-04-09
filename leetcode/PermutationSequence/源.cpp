#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        vector<int> factorial;
        factorial.push_back(1);
        list<int> ns;

        for (auto i = 1; i <= n; ++i)
        {
            ns.push_back(i);
            factorial.push_back(factorial.at(i - 1)*i);
        }
        k %= factorial.back();
        stringstream ss;
        for (auto i = n; i >0; --i)
        {
            int findex = k / factorial.at(i - 1);
            k %= factorial.at(i - 1);
            auto iter = ns.begin();
            int j = 0;
            while (j++ < findex)
                ++iter;
            ss << *iter;
            ns.remove(*iter);
            if (k == 0)
            {
                iter = ns.begin();
                while (iter!=ns.end())
                {
                    ss << *iter++;
                }
                return ss.str();
            }
        }
        return ss.str();
    }
};


int main()
{
    Solution s;
    cout << s.getPermutation(4, 7) << endl;
    system("pause");
}