#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class _Queue
{
private:
    deque<T> stack1;
    deque<T> stack2;
public:
    void push(T t)
    {
        stack1.push_back(t);
    }

    void _move()
    {
        while (!stack1.empty())
        {
            stack2.push_back(stack1.back());
            stack1.pop_back();
        }
    }

    void pop()
    {
        assert(!stack1.empty() || !stack2.empty());
        if (stack2.empty())
            _move();
        stack2.pop_back();
    }

    T peek()
    {
        assert(!stack1.empty() || !stack2.empty());
        if (stack2.empty())
            _move();
        return stack2.back();
    }
    bool empty(void)
    {
        return stack1.empty() && stack2.empty();
    }
};

typedef _Queue<int> Queue;


int main()
{
    Queue q;
    q.push(1);
    cout << q.peek() << endl;
    system("pause");
    return 0;
}