#include <iostream>
#include <algorithm>
#include "../leecode-II/leetcode.h"

using namespace std;


typedef _leetcode_listnode<int> ListNode;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *returnhead(head->next), *tmp(nullptr);
        ListNode _tmphead(0);
        auto tmphead = &_tmphead;
        tmphead->next = head;
        while (tmphead!=nullptr && tmphead->next != nullptr && tmphead->next->next != nullptr)
        {
            tmp = tmphead->next->next->next;
            tmphead->next->next->next = tmphead->next;
            tmphead->next = tmphead->next->next;
            tmphead->next->next->next = tmp;
            tmphead = tmphead->next->next;
        }
        return returnhead;
    }

    ListNode *swappairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode  *p(newhead), *q(head);
        while (q != nullptr && q->next != nullptr)
        {
            auto t(q->next->next);
            q->next->next = q;
            p->next = q->next;
            q->next = t;
            p = q;
            q = p->next;
        }
        return newhead->next;
    }
};

int main()
{
    Solution s;

    vector<int> test = { 1, 2, 3, 4, 5, 6, 7};
    auto l1 = lc_createlist(test, true);
    auto l2 = s.swappairs(l1);
    lc_printlist(l2);
    lc_destroylist(l2);
    system("pause");
    return 0;

}