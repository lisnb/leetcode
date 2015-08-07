#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.size() != popV.size())
            return false;
        if (pushV.empty())
            return true;
        vector<int> stack;
        int pushi(0), popi(0);
        while (pushi < pushV.size())
        {
            if (pushV.at(pushi) == popV.at(popi))
            {
                ++pushi;
                ++popi;
            }
            else
            {
                stack.push_back(pushV.at(pushi++));
            }
        }
        while (popi < popV.size())
        {
            if (stack.back() == popV.at(popi))
            {
                stack.pop_back();
                ++popi;
            }
            else
                return false;
        }
        return true;
    }
};



int main()
{
    Solution s;
    vector<int> pushV = { 1, 2, 3, 4, 5 };
    vector<int> popV = { 4, 5, 3, 1, 2};
    cout << s.IsPopOrder(pushV, popV)<<endl;
    system("pause");
    return 0;

}