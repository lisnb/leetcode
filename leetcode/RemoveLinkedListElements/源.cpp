#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL )
            return NULL;

        auto thead = head;
        while (thead!=NULL&&thead->val == val)
            thead = thead->next;
        if (thead == NULL)
            return NULL;

        auto shead = thead;
        while (shead->next!=NULL)
        {
            if(shead->next->val == val)
                shead->next = shead->next->next;
            else
                shead = shead->next;
        }

        return thead;
    }
};