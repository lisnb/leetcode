#include <list>
#include <algorithm>
#include <iostream>

using namespace std;



class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        list<int> circle;
        for (auto i = 0; i < n; ++i)
            circle.push_back(i);
        auto currentchild = circle.begin();
        int currentsize = n;
        while (currentsize>1)
        {
            //cout << currentsize << endl;
            for (auto i = 1; i < m; ++i)
            {
                ++currentchild;
                if (currentchild == circle.end())
                    currentchild = circle.begin();
            }
            auto next = ++currentchild;
            if (next == circle.end())
                next = circle.begin();
            --currentchild;
            circle.erase(currentchild);
            currentchild = next;
            --currentsize;
        }
        return circle.front();
    }
};


int main()
{
    Solution s;
    cout << s.LastRemaining_Solution(5, 3) << endl;
    system("pause");
    return 0;
}