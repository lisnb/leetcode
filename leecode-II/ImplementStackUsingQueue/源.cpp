#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;



class Stack {
public:
    Stack() :_top(-1)
    {
        this->stack = &q1;
        this->backup = &q2;
    };
    // Push element x onto stack.
    void push(int x) {
        this->stack->push(x);
        this->_top = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        while (this->stack->size() > 1)
        {
            _top = this->stack->front();
            this->backup->push(_top);
            this->stack->pop();
        }
        this->stack->pop();
        swap(this->stack, this->backup);
    }

    // Get the top element.
    int top() {
        return _top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return stack->empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
    queue<int> *stack;
    queue<int> *backup;
    int _top;
};



int main()
{
    Stack s;
    for (auto i = 0; i < 10; ++i)
    {
        s.push(i);
        cout << s.top() << endl;
    }
    for (auto i = 0; i < 5; ++i)
    {
        s.pop();
        cout << s.top() << endl;
    }
    for (auto i = 0; i < 8; ++i)
    {
        s.push(i*10);
        cout << s.top() << endl;
    }
    for (auto i = 0; i < 3; ++i)
    {
        s.pop();
        cout << s.top() << endl;
    }

    system("pause");
    return 0;

}