#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef _leetcode_listnode<int> ListNode;


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p1(head), *p2(head);
        while (p2->next!=nullptr && p2->next->next != nullptr)
        {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        p2 = p1->next;
        p1->next = nullptr;
        p1 = sortList(head);
        p2 = sortList(p2);
        head = mergeTwoLists(p1, p2);
        return head;
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *head;
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        auto tmp(head);
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            else
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        tmp->next = l1 == nullptr ? l2 : l1;
        return head;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode _tmp(0);
        ListNode *nhead(&_tmp), *looper(nullptr), *pivot_prev(head);
        nhead->next = head;
        ListNode *p1(nhead), *tmp(nullptr);
        while (pivot_prev != nullptr && pivot_prev->next != nullptr)
        {
            if (pivot_prev->val > pivot_prev->next->val)
            {
                looper = nhead;
                while (looper != pivot_prev && looper->next->val < pivot_prev->next->val)
                    looper = looper->next;
                tmp = looper->next;
                looper->next = pivot_prev->next;
                pivot_prev->next = pivot_prev->next->next;
                looper->next->next = tmp;
            }
            else
            {
                pivot_prev = pivot_prev->next;
            }

        }
        return nhead->next;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1};
    auto l1 = lc_createlist(test);
    auto l2 = s.sortList(l1);
    lc_printlist(l2);
    lc_destroylist(l2);
    system("pause");
    return 0;
}