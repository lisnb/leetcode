#include <iostream>
#include <vector>
#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <queue>

using namespace std;


typedef _leetcode_listnode<int> ListNode;


class Solution2 {
    struct cmp_greater_list
    {
        bool operator()(const ListNode *lh, const ListNode *rh) const
        {
            return lh->val > rh->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp_greater_list> minheap;
        for (auto list : lists)
        {
            if (list != nullptr)
                minheap.push(list);
        }

        ListNode *newhead = new ListNode(0);
        auto thead(newhead);
        while (!minheap.empty())
        {
            auto top = minheap.top();
            minheap.pop();
            thead->next = top;
            thead = thead->next;
            if (top->next != nullptr)
                minheap.push(top->next);
        }
        return newhead->next;
    }
};



class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
        if (lists.empty())
            return nullptr;
        int total(lists.size());
        while (total > 1)
        {
            int b(0), e(total - 1);
            while (b < e)
            {
                lists.at(b) = mergeTwoLists(lists.at(b), lists.at(e));
                ++b;
                --e;
            }
            total = b == e ? b + 1 : b;
        }
        return lists.front();
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *head;
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        auto tmp(head);
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            else
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        tmp->next = l1 == nullptr ? l2 : l1;
        return head;
    }
};



int main()
{
    Solution2 s;
    vector<int> v1 = { 10 }, v2 = { 2, 4, 6, 7, 8 }, v3 = {6, 7, 8,9,10};
    auto l1 = lc_createlist(v1, true), l2 = lc_createlist(v2, true), l3 = lc_createlist(v3);
    vector<ListNode *> lists = { l1, l2};
    auto l4 = s.mergeKLists(lists);
    lc_printlist(l4);
    lc_destroylist(l4);
    system("pause");
    return 0;
}