#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        
        if (height.empty())
            return 0;
        if (height.size() == 1)
            return height.at(0);
        vector<int> stack;
        vector<int> leftlargest(height.size(), 0);
        for (auto i = 0; i < height.size(); ++i)
        {
            int tmp(i);
            while (!stack.empty() && height.at(i) <= height.at(stack.back()))
            {
                tmp = leftlargest.at(stack.back());
                stack.pop_back();
            }
            leftlargest.at(i) = tmp;
            stack.push_back(i);
        }
        stack.clear();
        vector<int> rightlargest(height.size(), 0);

        for (int i = height.size() - 1; i >= 0; --i)
        {
            int tmp(i);
            while (!stack.empty() && height.at(i) <= height.at(stack.back()))
            {
                tmp = rightlargest.at(stack.back());
                stack.pop_back();
            }
            rightlargest.at(i) = tmp;
            stack.push_back(i);
        }

        int largestra(0);
        for (auto i = 0; i < height.size(); ++i)
        {
            largestra = max(largestra, height.at(i)*(rightlargest.at(i) - leftlargest.at(i) + 1));
        }
        return largestra;
    }

    int largestRectangleArea2(vector<int> &height)
    {
        int len(height.size());
        if (len == 0)
            return 0;
        if (len == 1)
            return height.at(0);

        stack<int> index;
        vector<int> lefts(len, 0), rights(len, 0);
        int tmp(-1);
        for (auto i = 0; i < len; ++i)
        {
            tmp = i;
            while (!index.empty() && height.at(i) <= height.at(index.top()))
            {
                tmp = lefts[index.top()];
                index.pop();
            }
            lefts.at(i) = tmp;
            index.push(i);
        }

        while (!index.empty())
            index.pop();

        for (int i = len - 1; i >= 0; --i)
        {
            tmp = i;
            while (!index.empty() && height.at(i) <= height.at(index.top()))
            {
                tmp = rights[index.top()];
                index.pop();
            }
            rights.at(i) = tmp;
            index.push(i);
        }
        for (auto l : lefts)
            cout << l << " ";
        cout << endl;
        for (auto r : rights)
            cout << r << " ";
        cout << endl;
        int maxa(-1);
        for (auto i = 0; i < len; ++i)
        {
            maxa = max(maxa, height.at(i)*(rights.at(i) - lefts.at(i) + 1));
        }

        return maxa;

    }
};

int main()
{
    Solution s;
    vector<int> test = {5, 5, 5 };
    cout << s.largestRectangleArea(test) << endl;
    system("pause");
    return 0;
}