#include "../leecode-II/leetcode.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef _leetcode_listnode<int> ListNode;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return nullptr;
        auto p1(head);
        while (n-- > 0)
            p1 = p1->next;
        if (p1 == nullptr)
            return head->next;
        auto p2(head);
        while (p1->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};