#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
using namespace std;



typedef _leetcode_listnode<int> ListNode;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        auto p1(headA), p2(headB);
        int len1(1), len2(1);
        while (p1->next != nullptr)
        {
            ++len1;
            p1 = p1->next;
        }
        while (p2->next != nullptr)
        {
            ++len2;
            p2 = p2->next;
        }
        if (p1 != p2)
            return nullptr;
        auto llist = len1 > len2 ? headA : headB;
        auto slist = len1 > len2 ? headB : headA;
        auto diff(abs(len1 - len2));
        p1 = llist;
        p2 = slist;
        while (diff-- > 0)
            p1 = p1->next;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1, 2, 3, 4, 5 };
    auto l1 = lc_createlist(test);
    auto l2 = s.getIntersectionNode(l1, l1);
    system("pause");
    return 0;
}