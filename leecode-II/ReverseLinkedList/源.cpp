#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef _leetcode_listnode<int> ListNode;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newhead(nullptr), *newtail(nullptr);
        lc_reverselist(head, nullptr, newhead, newtail);
        return newhead;
    }

private:
    void lc_reverselist(ListNode *head, ListNode* tail, ListNode *&newhead, ListNode *&newtail)
    {
        if (head == tail)
        {
            newhead = tail;
            newtail = tail;
            return;
        }
        newtail = head;
        newhead = head;
        ListNode *originalhead(head->next), *tmp(nullptr);
        newtail->next = nullptr;
        while (originalhead != tail)
        {
            tmp = originalhead->next;
            originalhead->next = newhead;
            newhead = originalhead;
            originalhead = tmp;
        }
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1};
    auto l1 = lc_createlist(test, true);
    auto l2 = s.reverseList(l1);
    lc_printlist(l2);
    lc_destroylist(l2);
    system("pause");
    return 0;

}