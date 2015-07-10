#include <algorithm>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;
        if (tokens.size() == 1)
            return stoi(tokens.at(0));
        vector<int> stack;
        for (auto token : tokens)
        {
            if (!isop(token))
                stack.push_back(stoi(token));
            else
            {
                int irh = stack.back();
                stack.pop_back();
                int ilh = stack.back();
                stack.pop_back();
                stack.push_back(alu(ilh, irh, token));
            }
        }
        return stack.back();
    };

private:
    bool isop(const string &op)
    {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }
    int alu(const string &lh, const string &rh, const string op)
    {
        int ilh = stoi(lh), irh = stoi(rh);
        return alu(ilh, irh, op);
    }

    int alu(int ilh, int irh, const string &op)
    {
        if (op == "+")
            return ilh + irh;
        else if (op == "-")
            return ilh - irh;
        else if (op == "*")
            return ilh*irh;
        else
            return ilh / irh;
    }
};

int main()
{
    Solution s;
    vector<string> test = { "2", "1", "+", "3", "*" };
    cout << s.evalRPN(test) << endl;
    system("pause");
    return 0;
}