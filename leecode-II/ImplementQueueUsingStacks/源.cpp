#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;




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