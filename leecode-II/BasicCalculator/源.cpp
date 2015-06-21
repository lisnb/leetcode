#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>


using namespace std;


class Solution {
public:
    int calculate(string s) {
        int i(0);
        vector<string> st;
        while (i < s.size())
        {
            if (s.at(i) == ' ')
            {
                ++i;
                continue;
            }
            else if (s.at(i) == '(' || s.at(i) == '+' || s.at(i) == '-')
                st.push_back(s.substr(i, 1));
            else if (s.at(i) == ')')
            {
                string tmp = st.back();
                st.pop_back();
                st.pop_back();
                if (!st.empty())
                {
                    if (st.back() == "+" || st.back() == "-")
                    {
                        string op = st.back();
                        st.pop_back();
                        string lhs = st.back();
                        st.pop_back();
                        tmp = cal(lhs, tmp, op);
                    }
                }
                st.push_back(tmp);
            }
            else
            {
                string hs("");
                while (i < s.size() && isdigit(s.at(i)))
                {
                    hs += s.at(i);
                    ++i;
                }
                --i;
                if (st.empty())
                {
                    st.push_back(hs);
                }
                else
                {
                    string op = st.back();
                    if (op == "+" || op == "-")
                    {
                        st.pop_back();
                        string lhs = st.back();
                        st.pop_back();
                        st.push_back(cal(lhs, hs, op));
                    }
                    else
                    {
                        st.push_back(hs);
                    }
                }
            }
            ++i;
        }
        return stoi(st.back());
    }

private:
    void caltobottom(stack<string> &st)
    {
        return;
    }
    string cal(string &lhs, string &rhs, const string &op)
    {
        int lh(stoi(lhs));
        int rh(stoi(rhs));
        if (op == "+")
            return to_string(lh + rh);
        else if (op == "-")
            return to_string(lh - rh);
        else
            return "0";
    }
};



int main()
{
    Solution s;
    //string problem("(1+(4+5+2)-3)+(6+8)");
    string problem("1-(4+5+2)-3");
    cout << s.calculate(problem) << endl;
    system("pause");
    return 0;
}