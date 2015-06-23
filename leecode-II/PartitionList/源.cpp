#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef _leetcode_listnode<int> ListNode;



class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode _tmp(0);
        ListNode *newhead(&_tmp);
        newhead->next = head;
        ListNode *p1(newhead), *p2(newhead), *lastgte(nullptr), *tmp(nullptr);
        while (p2->next != nullptr && p2->next->val<x)
            p2 = p2->next;
        if (p2->next == nullptr)
            return head;
        p1 = p2;
        while (p2->next != nullptr)
        {
            if (p2->next->val >= x)
                p2 = p2->next;
            else
            {
                tmp = p1->next;
                p1->next = p2->next;
                p2->next = p2->next->next;
                p1->next->next = tmp;
                p1 = p1->next;

            }
        }

        return newhead->next;
    }
};



int main()
{
    Solution s;
    vector<int> test = {6, 7, 5, 1, 4, 3, 2, 5, 5};
    auto l1 = lc_createlist(test);
    auto l2 = s.partition(l1, 3);
    lc_printlist(l2);
    system("pause");
    return 0;
}