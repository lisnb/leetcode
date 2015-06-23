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

        ListNode _tmp(0);
        ListNode *p1(&_tmp);
        ListNode *p2(head);
        ListNode *p3(p1);
        while (p2 != nullptr)
        {
            if (p2->next == nullptr)
            {
                p3->next = p2;
                p3->next->next = nullptr;
                return p1->next;
            }
            if (p2->val != p2->next->val)
            {
                p3->next = p2;
                p3 = p3->next;
                p2 = p2->next;
                p3->next = nullptr;
            }
            else
            {
                int current(p2->val);
                while (p2!=nullptr && p2->val==current)
                    p2 = p2->next;
            }
        }
        return p1->next;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 2};
    auto l1 = lc_createlist(test, true);
    auto l2 = s.deleteDuplicates(l1);
    lc_printlist(l2);
    system("pause");
    return 0;
}

