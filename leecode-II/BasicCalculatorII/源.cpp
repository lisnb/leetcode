#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>

using namespace std;



class Solution {
public:
    int calculate(string s) {
        index = 0;
        int i(0);
        deque<string> equation;
        string currentelement("");
        while (true)
        {
            int sign = getnextelement(s, currentelement);
            if (sign == -1)
                break;
            if (sign < 2)
                equation.push_back(currentelement);
            else
            {
                string rh("");
                getnextelement(s, rh);
                string lh = equation.back();
                equation.pop_back();
                equation.push_back(alu(lh, rh, currentelement));
            }
        }
        while (equation.size() > 1)
        {
            string lh(equation.front());
            equation.pop_front();
            string op(equation.front());
            equation.pop_front();
            string rh(equation.front());
            equation.pop_front();
            equation.push_front(alu(lh, rh, op));
        }

        return equation.empty()?0:stoi(equation.front());
    }
private:
    int index;

    int getnextelement(string &s, string &next)
    {
        if (index >= s.size())
            return -1;
        while (index < s.size() && s.at(index) == ' ')
            ++index;
        if (index == s.size())
            return -1;
        if (s.at(index) == '+' || s.at(index) == '-')
        {
            next = s.substr(index, 1);
            ++index;
            return 1;
        }
        else if (s.at(index) == '*' || s.at(index) == '/')
        {
            next = s.substr(index, 1);
            ++index;
            return 2;
        }
        else
        {
            int numberbegin(index);
            while (index < s.size() && isdigit(s.at(index)))
                ++index;
            next = s.substr(numberbegin, index - numberbegin);
            return 0;
        }
    }

    string alu(string &lh, string &rh, string op)
    {
        int ilh = stoi(lh);
        int irh = stoi(rh);
        int result(0);
        if (op == "+")
            result = ilh + irh;
        else if (op == "-")
            result = ilh - irh;
        else if (op == "*")
            result = ilh*irh;
        else
            result = ilh / irh;
        return to_string(result);
    }
};


int main()
{
    Solution s;
    vector<string> test = {
        "3+2*2",
        " 3/2 ",
        " 3+5 / 2 ",
        "   3-2-3-6*7+9*7"
    };
    for (auto t : test)
        cout << t << "=" << s.calculate(t) << endl;
    system("pause");
    return 0;
}