#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if (s.size() <= 1)
            return false;
        deque<char> stack;
        for (auto c : s)
        {
            if (stack.empty())
            {
                if (isback(c))
                    return false;
                stack.push_back(c);
            }
            else 
            {
                if (ispair(stack.back(), c))
                    stack.pop_back();
                else
                {
                    if (isback(c))
                        return false;
                    else
                        stack.push_back(c);
                }
            }
        }
        return stack.empty();
    }
private:
    bool isback(char c)
    {
        return c == '}' || c == ']' || c == ')';
    }

    bool ispair(char c1, char c2)
    {
        return (c1 == '('&&c2 == ')') || (c1 == '{'&&c2 == '}') || (c1 == '['&&c2 == ']');
    }
};



int main()
{
    Solution s;
    string test("{}[])");
    cout << s.isValid(test) << endl;
    system("pause");
    return 0;
}