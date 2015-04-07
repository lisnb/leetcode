#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


class MinStack {
public:
    void push(int x) {
        stack.push_back(x);
        if (stack.size() == 1)
        {
            minindex.push_back(0);
        }
        else
        {
            if (x < stack.at(minindex.back()))
            {
                minindex.push_back(stack.size() - 1);
            }
            else{
                minindex.push_back(minindex.back());
            }
        }
    }

    void pop() {
        if (stack.size()>0)
        {
            stack.pop_back();
            minindex.pop_back();
        }
    }

    int top() {
        if (stack.size() > 0)
            return stack.back();
        else
            return -1;
    }

    int getMin() {
        if (stack.size() > 0)
            return stack.at(minindex.back());
        else
            return -1;
    }
private:
    vector<int> stack;
    vector<int> minindex;
};



int main()
{
    MinStack minstack;
    minstack.push(1);
    cout << minstack.getMin()<<"  "<<minstack.top() << endl;
    minstack.push(2);
    cout << minstack.getMin() << "  " << minstack.top() << endl;
    minstack.push(3);
    cout << minstack.getMin() << "  " << minstack.top() << endl;
    minstack.push(4);
    cout << minstack.getMin() << "  " << minstack.top() << endl;
    minstack.push(3);
    cout << minstack.getMin() << "  " << minstack.top() << endl;
    minstack.push(-10);
    cout << minstack.getMin() << "  " << minstack.top() << endl;
    minstack.pop();
    cout << minstack.getMin() << "  " << minstack.top() << endl;
    minstack.pop();
    minstack.pop();
    minstack.pop();
    minstack.pop();
    minstack.pop();
    cout << minstack.getMin() << "  " << minstack.top() << endl;
    system("pause");
}