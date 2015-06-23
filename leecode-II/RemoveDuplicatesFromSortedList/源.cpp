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


int main()
{
    Solution s;
    vector<int> test = { 1, 1, 2, 3, 3, 3, 4 };
    auto l1 = lc_createlist(test, true);
    auto l2 = s.deleteDuplicates(l1);
    lc_printlist(l2);
    system("pause");
    return 0;
}

