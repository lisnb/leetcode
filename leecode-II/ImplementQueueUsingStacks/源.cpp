#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;


class Queue2{
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    void _move()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    
    void push(int x)
    {
        stack1.push(x);
    }

    void pop(void)
    {
        if (stack2.empty())
            _move();
        if (stack2.empty())
            return;
        else
            stack2.pop();
    }
    int peek(void)
    {
        if (stack2.empty())
            _move();
        if (stack2.empty())
            return -1;
        return stack2.top();
    }

    bool empty(void)
    {
        return stack1.empty() && stack2.empty();
    }
};


class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!primary.empty())
        {
            temp.push(primary.top());
            primary.pop();
        }
        temp.push(x);
        while (!temp.empty())
        {
            primary.push(temp.top());
            temp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        primary.pop();
    }

    // Get the front element.
    int peek(void) {
        return primary.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return primary.empty();
    }

private:
    stack<int> primary;
    stack<int> temp;
};


int main()
{
    Queue queue;
    queue.push(1);
    cout << queue.peek() << endl;
    queue.push(2);
    cout << queue.peek() << endl;
    queue.push(3);
    cout << queue.peek() << endl;
    queue.push(4);
    cout << queue.peek() << endl;
    queue.pop();
    cout << queue.peek() << endl;
    queue.pop();
    cout << queue.peek() << endl;
    cout << queue.empty() << endl;
    system("pause");
    return 0;
}