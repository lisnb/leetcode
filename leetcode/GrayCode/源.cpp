#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> re;
        if (n == 0)
        {
            re.push_back(0);
            return re;
        }
        vector<string> tmp;
        string seed(n, '0');
        tmp.push_back(seed);
        grayCode(n, tmp, 2);
        
        for (auto t : tmp)
        {
            re.push_back(b2i(t));
        }
        return re;
    }

    int b2i(const string &s)
    {
        int i = 0;
        for (auto c : s)
        {
            i = (i * 2 + (c == '0' ? 0 : 1));
        }
        return i;
    }

    void grayCode(int n, vector<string> &prefix, int level)
    {
        if (level > (1 << n))
            return;
        string t = prefix.back();
        for (auto i = t.size()-1; i>=0; --i)
        {
            if (t.at(i) == '0')
            {
                t.at(i) = '1';
            }
            else
                t.at(i) = '0';
            if (find(prefix.begin(), prefix.end(), t) == prefix.end())
            {
                prefix.push_back(t);
                grayCode(n, prefix, level + 1);
                break;
                //prefix.pop_back(t);
            }
            else
            {
                t = prefix.back();
            }
        }
    }
};



int main()
{
    Solution s;
    vector<int> test = {0, 1, 2, 3};
    for (auto t : test)
    {
        cout << t << endl;
        for (auto tt : s.grayCode(t))
        {
            cout << tt << " ";
        }
        cout << endl;
    }
    system("pause");
}