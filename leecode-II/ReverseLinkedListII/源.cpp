#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef _leetcode_listnode<int> ListNode;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr)
            return head;
        ListNode _tmp(0); 
        ListNode *p1(&_tmp);
        p1->next = head;
        int mm(m);
        while (mm-- > 1)
            p1 = p1->next;
        ListNode *newhead, *newtail;
        lc_reverselist(p1->next, newhead, newtail, n - m+1);
        p1->next = newhead;
        return m == 1 ? newhead : head;
    }

private:
    void lc_reverselist(ListNode *head, ListNode *&newhead, ListNode *&newtail, int cnt)
    {
        int cctn(1);
        newtail = head;
        newhead = head;
        ListNode *originalhead(head->next), *tmp(nullptr);
        newtail->next = nullptr;
        while (cctn<cnt)
        {
            tmp = originalhead->next;
            originalhead->next = newhead;
            newhead = originalhead;
            originalhead = tmp;
            ++cctn;
            
        }
        newtail->next = originalhead;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 3, 4, 5 };
    auto l1 = lc_createlist(test, true);
    auto l2 = s.reverseBetween(l1, 1, 4);
    lc_printlist(l2);
    lc_destroylist(l2);
    system("pause");
    return 0;

}