#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> re;
    
        vector<int> num;
        
        bfs(num, re, 1, n, k, 0);

        return re;
    }

    void bfs(vector<int> &prefix, vector<vector<int>> &re, int b, int n, int k, int level)
    {
       
        if (level == k)
        {
            re.push_back(prefix);
            return;
        }
        if (b > n)
            return;
        for (auto i = b; i <=n; ++i)
        {
            prefix.push_back(i);
            bfs(prefix, re, i + 1, n, k, level + 1);
            prefix.pop_back();
        }
    }


    void permute(vector<int> &num, vector<vector<int>> &re, vector<int>::size_type i, int k)
    {
        if (i == k)
        {
           
            return;
        }
        for (auto j = i; j < num.size(); ++j)
        {
            swap(num.at(i), num.at(j));
            if (i + 1 == k)
            {
                vector<int> tmp(num.begin(), num.begin() + k);
                re.push_back(tmp);
            }
            else
                permute(num, re, i + 1, k);
            swap(num.at(i), num.at(j));
        }
    }



    vector<vector<int> > combineMLE(int n, int k) {
        vector<vector<int>> re;
        if (n == 0 || k == 0 || n<k)
            return re;
        vector<int> num;
        for (auto i = 1; i <= n; ++i)
            num.push_back(i);
        permuteMLE(num, re, 0, k);
        return re;
    }

    void permuteMLE(vector<int> &num, vector<vector<int>> &re, vector<int>::size_type i, int k)
    {
        if (i == k)
        {
            vector<int> tmp(num.begin(), num.begin() + k);
            re.push_back(tmp);
            return;
        }
        for (auto j = i; j < num.size(); ++j)
        {
            swap(num.at(i), num.at(j));
            permuteMLE(num, re, i + 1, k);
            swap(num.at(i), num.at(j));
        }
    }
};


int main()
{
    Solution s;
    vector<pair<int, int>> test = {
        /*{4, 2},*/
        {4,3},
        {3,3},
        {2,1},
        {4,1},
        {0,0},
        {4,0}
    };
    for (auto t : test)
    {
        cout << t.first << ", " << t.second << endl;
        for (auto tt : s.combine(t.first, t.second))
        {
            for (auto ttt : tt)
            {
                cout << ttt << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    system("pause");



}