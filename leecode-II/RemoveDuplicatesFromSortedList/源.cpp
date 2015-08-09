#include <iostream>
#include <algorithm>
#include <vector>
#include "../leecode-II/leetcode.h"


using namespace std;

typedef _leetcode_listnode<int> ListNode;


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p1(head), *tmp(nullptr);
        while (p1->next != nullptr)
        {
            if (p1->next->val == p1->val)
            {
                p1->next = p1->next->next;
            }
            else
                p1 = p1->next;
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *newhead = new ListNode(0);
        newhead->next = pHead;
        ListNode *p1(newhead), *p2(pHead->next);
        int cur(pHead->val), cnt(1);
        while (true)
        {
            while (p2 != nullptr&&p2->val == cur)
            {
                ++cnt;
                p2 = p2->next;
            }
            if (cnt == 1)
            {
                p1->next->val = cur;
                p1 = p1->next;
            }
            if (p2 == nullptr)
                break;
            cur = p2->val;
            cnt = 1;
            p2 = p2->next;
        }
        p1->next = nullptr;
        return newhead->next;
    }
};


int main()
{
    Solution2 s;
    vector<int> test = { 1, 2, 34 };
    auto l1 = lc_createlist(test, true);
    //auto l2 = s.deleteDuplicates(l1);
    auto l2 = s.deleteDuplication(l1);
    lc_printlist(l2);
    system("pause");
    return 0;
}

