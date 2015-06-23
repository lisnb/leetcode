#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef _leetcode_listnode<int> ListNode;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto p1(head);
        int size(0);
        while (p1 != nullptr)
        {
            ++size;
            p1 = p1->next;
        }
        k %= size;
        if (k == 0)
            return head;
        ListNode _tmp(0);
        p1 = &_tmp;
        p1->next = head;
        auto pivot(p1);
        int pk(size - k);
        while (pk-- > 0)
            pivot = pivot->next;
        lc_reverselist(pivot, k);
        lc_printlist(p1->next);
        lc_reverselist(p1, size - k);
        lc_printlist(p1->next);
        lc_reverselist(p1, size);
        
        return p1->next;
    }
private:
    ListNode* lc_reverselist(ListNode *head_prev, int cnt)
    {
        if (cnt == 1)
            return head_prev->next;
        int ccnt(1);
        ListNode *newhead(head_prev->next), *newtail(head_prev->next);
        ListNode *originalhead(head_prev->next->next), *tmp(nullptr);
        newtail->next = nullptr;
        while (ccnt<cnt)
        {
            tmp = originalhead->next;
            originalhead->next = newhead;
            newhead = originalhead;
            originalhead = tmp;
            ++ccnt;
        }
        newtail->next = originalhead;
        head_prev->next = newhead;
        return newtail;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 3, 4, 5, 6, 7 };
    auto l1 = lc_createlist(test, true);
    auto l2 = s.rotateRight(l1, 3);
    lc_printlist(l2);
    lc_destroylist(l2);
    system("pause");
    return 0;

}