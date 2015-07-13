#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class MinStack {
public:
    void push(int x) {
        if (container.empty())
        {
            container.push_back(x);
            minindex.push_back(0);
        }
        else
        {
            container.push_back(x);
            minindex.push_back(x < container.at(minindex.back()) ? container.size() - 1 : minindex.back());
        }
    }

    void pop() {
        if (container.empty())
            return;
        container.pop_back();
        minindex.pop_back();
    }

    int top() {
        return container.back();
    }

    int getMin() {
        if (container.empty())
            return -1;
        return container.at(minindex.back());
    }

private:
    vector<int> container;
    vector<int> minindex;
};