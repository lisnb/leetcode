#include <algorithm>
#include <iostream>
#include <vector>
#include <string>



using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1)
            return s.size();
        int longest(0);
        vector<int> stack;


        for (auto index = 0; index < s.size(); ++index)
        {
            if (s.at(index) == '(')
                stack.push_back(-1 * (index + 1));
            else
            {
                if (!stack.empty() && stack.back() < 0)
                {
                    stack.pop_back();
                    if (!stack.empty())
                    {
                        longest = max(longest, index + 1 - abs(stack.back()));
                    }
                    else
                        longest = index + 1;
                }
                else
                    stack.push_back(index + 1);
            }
        }

        return longest;
    }
};

int main()
{
    Solution s;
    string test("()()())");
    cout << s.longestValidParentheses(test) << endl;
    system("pause");
    return 0;
}