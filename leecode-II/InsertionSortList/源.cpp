#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef _leetcode_listnode<int> ListNode;


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode _tmp(0);
        ListNode *nhead(&_tmp), *looper(nullptr), *pivot_prev(head);
        nhead->next = head;
        ListNode *p1(nhead), *tmp(nullptr);
        while (pivot_prev!=nullptr && pivot_prev->next != nullptr)
        {
            if (pivot_prev->val > pivot_prev->next->val)
            {
                looper = nhead;
                while (looper != pivot_prev && looper->next->val < pivot_prev->next->val)
                    looper = looper->next;
                tmp = looper->next;
                looper->next = pivot_prev->next;
                pivot_prev->next = pivot_prev->next->next;
                looper->next->next = tmp;
            }
            else
            {
                pivot_prev = pivot_prev->next;
            }
            
        }
        return nhead->next;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1, 2 , 6, 4, 7, 8, 34};
    auto l1 = lc_createlist(test);
    auto l2 = s.insertionSortList(l1);
    lc_printlist(l2);
    lc_destroylist(l2);
    system("pause");
    return 0;
}