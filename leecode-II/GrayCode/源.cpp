#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return{ 0 };
        vector<vector<int>> gre;
        gre.reserve(1 << n);
        backtrack(n, gre);
        vector<int> re;
        re.reserve(1 << n);
        for (auto ggre : gre)
        {
            re.push_back(btoi(ggre));
        }
        return re;
    }

public:
    vector<int> grayCode2(int n)
    {
        vector<int> re;
        re.push_back(0);
        if (n > 0)
        {
            re.push_back(1);
        }
        else
        {
            return re;
        }
        int a(1);
        for (int i = 1; i < n; ++i)
        {
            a<<=1;
            for (int j = re.size() - 1; j >= 0; --j)
            {
                re.push_back(re.at(j) + a);
            }

        }
        return re;
    }

private:
    int btoi(const vector<int> &gray)
    {
        int i = 0;
        for (auto ri = gray.crbegin(); ri != gray.crend(); ++ri)
        {
            i = i * 2 + *ri;
        }
        return i;
    }

    void backtrack(int n, vector<vector<int>> &re)
    {
        if (n == 1)
        {
            //vector<vector<int>> re;
            re.push_back({ 0 });
            re.push_back({ 1 });
            return ; re;
        }
        else
        {
            vector<vector<int>> tre;
            tre.reserve(1 << n);
            backtrack(n - 1, tre);
            for (auto iter = tre.begin(); iter != tre.end(); ++iter)
            {
                re.push_back(*iter);
                re.back().push_back(0);
            }
            for (auto riter = tre.rbegin(); riter != tre.rend(); ++riter)
            {
                re.push_back(*riter);
                re.back().push_back(1);
            }
        }
    }
};


int main()
{
    Solution s;
    auto re = s.grayCode2(3);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}