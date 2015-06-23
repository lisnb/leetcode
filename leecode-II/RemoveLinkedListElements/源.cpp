#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
using namespace std;



typedef _leetcode_listnode<int> ListNode;


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        ListNode _tmp(0);
        ListNode *p1(&_tmp);
        auto p2(head), p3(p1);
        while (p2 != nullptr)
        {
            if (p2->val != val)
            {
                p3->next = p2;
                p3 = p3->next;
                p2 = p2->next;
                p3->next = nullptr;
            }
            else
            {
                p2 = p2->next;
            }
        }
        return p1->next;    
    }
};

int main()
{
    Solution s;
    vector<int> test = { 6 };
    auto l1 = lc_createlist(test);
    auto l2 = s.removeElements(l1, 6);
    lc_printlist(l2);
    system("pause");
    return 0;
}