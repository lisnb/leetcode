#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


typedef _leetcode_listnode<int> ListNode;





class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        auto t(head);
        while (t != nullptr)
        {
            nums.push_back(t->val);
            t = t->next;
        }
        int b(0), e(nums.size() - 1);
        while (b < e)
        {
            if (nums.at(b++) != nums.at(e--))
                return false;
        }
        return true;
    }
};


class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        
    }

private:

    bool issame(ListNode *l1, ListNode *l2)
    {
        ListNode *h1(l1), *h2(l2);
        while (h1 != nullptr)
        {
            if (h1->val != h2->val)
                return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }

    void reverselist_i(ListNode *begin, ListNode *end)
    {
        auto head(begin);
        auto t(begin->next);
        head->next = nullptr;
        while (t != end)
        {
            auto temp = t->next;
            t->next = head;
            head = t;
            t = temp;
        }
        begin = head;
    }
};