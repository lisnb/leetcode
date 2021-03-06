#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef _leetcode_listnode<int> ListNode;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        auto p1(head), p2(head);
        while (p2!=nullptr && p2->next != nullptr )
        {
            p2 = p2->next->next;
            p1 = p1->next;
            if (p1 == p2)
                return true;
        }
        return false;
    }
};