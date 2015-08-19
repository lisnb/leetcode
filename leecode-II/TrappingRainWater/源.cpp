#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;
        //deque<int> stack;
        vector<int> leftmaxes(height.size(), 0);
        int leftmax(0);
        for (auto i = 1; i < height.size() - 1; ++i)
        {
            leftmax = max(leftmax, height.at(i - 1));
            leftmaxes.at(i) = leftmax;
        }
        int rightmax(0), trapsum(0), tmp(0);
        //vector<int> rightmaxes(height.size(), 0);
        for (int i = height.size() - 2; i > 0; --i)
        {
            rightmax = max(rightmax, height.at(i + 1));
            //rightmaxes.at(i) = rightmax;
            tmp = min(leftmaxes.at(i), rightmax);
            if (tmp>height.at(i))
                trapsum += (tmp - height.at(i));
        }

        return trapsum;
    }
};


class Solution2 {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1)
            return 0;
        vector<int> lefts(height.size());
        int leftmax(0); 
        for (auto i = 0; i < height.size(); ++i)
        {
            leftmax = max(leftmax, height[i]);
            lefts[i] = leftmax;
        }

        int water(0), rightmax(0);
        for (int i = height.size() - 1; i >= 0; --i)
        {
            rightmax = max(rightmax, height[i]);
            water += (min(rightmax, lefts[i]) - height[i]);
        }
        return water;
    }
};

int main()
{
    Solution2 s;
    vector<int> test = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << s.trap(test) << endl;
    system("pause");
    return 0;
}