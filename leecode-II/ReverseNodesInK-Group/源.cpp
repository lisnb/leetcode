#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef _leetcode_listnode<int> ListNode;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;
        ListNode _tmp(0);
        ListNode *p1(&_tmp);
        p1->next = head;
        ListNode *prehead(p1), *tail(p1);
        while (true)
        {
            int position(0);
            while (tail->next != nullptr)
            {
                tail = tail->next;
                ++position;
                if (position == k)
                    break;
            }
            if (position == k)
                tail = lc_reverselist(p1, k);
            else
                return prehead->next;
            p1 = tail;
        }
        
    }

private:
    ListNode* lc_reverselist(ListNode *head_prev,  int cnt)
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
    vector<int> test = { 1, 2, 3, 4, 5 };
    auto l1 = lc_createlist(test, true);
    auto l2 = s.reverseKGroup(l1, 1);
    lc_printlist(l2);
    lc_destroylist(l2);
    system("pause");
    return 0;

}