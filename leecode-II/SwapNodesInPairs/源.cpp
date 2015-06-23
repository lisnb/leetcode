#include <iostream>
#include <algorithm>
#include "../leecode-II/leetcode.h"

using namespace std;


typedef _leetcode_listnode<int> ListNode;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *returnhead(head->next), *tmp(nullptr);
        ListNode _tmphead(0);
        auto tmphead = &_tmphead;
        tmphead->next = head;
        while (tmphead!=nullptr && tmphead->next != nullptr && tmphead->next->next != nullptr)
        {
            tmp = tmphead->next->next->next;
            tmphead->next->next->next = tmphead->next;
            tmphead->next = tmphead->next->next;
            tmphead->next->next->next = tmp;
            tmphead = tmphead->next->next;
        }
        return returnhead;
    }
};

int main()
{
    Solution s;

    vector<int> test = { 1, 2, 3, 4, 5, 6, 7};
    auto l1 = lc_createlist(test, true);
    auto l2 = s.swapPairs(l1);
    lc_printlist(l2);
    lc_destroylist(l2);
    system("pause");
    return 0;

}