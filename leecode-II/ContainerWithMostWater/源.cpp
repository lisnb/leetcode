#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>

using namespace std;



class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;
        int maxc(0);
        for (auto i = 0; i < height.size() - 1; ++i)
        {
            for (int j = height.size() - 1; j > i; --j)
            {
                if (height.at(j) >= height.at(i))
                {
                    maxc = max(maxc, (j - i)*height.at(i));
                    break;
                }
                else
                {
                    maxc = max(maxc, (j - i)*height.at(j));
                }
            }
            while (i + 1 < height.size() && height.at(i) >= height.at(i + 1))
                ++i;
        }
        return maxc;
            
    }
};