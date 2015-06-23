#include <iostream>
#include <vector>
#include "../leecode-II/leetcode.h"
#include <algorithm>

using namespace std;


typedef _leetcode_listnode<int> ListNode;


class Solution {
public:
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
};



int main()
{
    Solution s;
    vector<int> v1 = { 10}, v2 = { 2, 4, 6, 7, 8 };
    auto l1 = lc_createlist(v1, true), l2 = lc_createlist(v2, true);
    auto l3 = s.mergeTwoLists(l1, l2);
    lc_printlist(l3);
    lc_destroylist(l3);
    system("pause");
    return 0;
}