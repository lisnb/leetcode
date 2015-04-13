#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1)
            return 0;
        stack<int> indexes;
        int longest(0);
        for (auto i = 0; i < s.size(); ++i)
        {
            if (s.at(i) == '(')
                indexes.push(-1 * (i + 1));
            else
            {
                if (!indexes.empty() && indexes.top() < 0)
                {
                    indexes.pop();
                    if (indexes.empty())
                    {
                        longest = i + 1;
                    }
                    else
                    {
                        int index = abs(indexes.top());
                        longest = max(longest, i - index + 1);
                    }
                }
                else
                {
                    indexes.push(i + 1);
                }
            }
        }
        return longest;
    }
};