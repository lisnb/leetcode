#include "../nowcoder/nowcoder.h"
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


template<typename T>
void reversestack(stack<T> &sta, int remain)
{
    if (sta.size() == remain)
        return;
    int t1 = sta.top();
    sta.pop();
    int t2 = sta.top();
    sta.pop();
    sta.push(t1);
    reversestack(sta, remain);
    sta.push(t2);
}

template<typename T>
void reverseastack(stack<T> &sta, int remain)
{
    if (remain == 0)
        return;
    reverseastack(sta, remain - 1);
    reversestack(sta, remain);
}



typedef _leetcode_listnode<int> ListNode;
bool ispalindrome(ListNode *head, ListNode *tail=nullptr)
{
    if (head==nullptr)
}



int main()
{
    stack<int> sta;
    for (auto i = 0; i < 5; ++i)
        sta.push(i);
    reverseastack(sta, sta.size());

    while (!sta.empty())
    {
        cout << sta.top() << endl;
        sta.pop();
    }
    system("pause");
    return 0;
}
