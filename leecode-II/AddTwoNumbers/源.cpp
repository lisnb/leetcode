#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include "../leecode-II/leetcode.h"

using namespace std;


typedef unsigned long long bigint;

bigint gcd(bigint a, bigint b)
{
    bigint tmp(0);
    while (a != 0)
    {
        tmp = a;
        a = b%a;
        b = tmp;
    }
    return b;
}

bigint gcd2(bigint a, bigint b)
{
    return b == 0 ? a : gcd2(b, a%b);
}

bigint gcd3(bigint a, bigint b)
{
    bigint tmp(0);
    while (b != 0)
    {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

typedef _leetcode_listnode<int> ListNode;


class Solution {
public:
    ListNode* addTwoNumbersInPlace(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        int carry(0), tempsum(0);
        auto tl1(l1), tl2(l2), head(l1);
        while (tl1->next != nullptr&&tl2->next != nullptr)
        {
            tempsum = carry + tl1->val + tl2->val;
            carry = tempsum / 10;
            tl1->val = tempsum % 10;
            tl1 = tl1->next;
            tl2 = tl2->next;
        }
        if (tl1->next == nullptr)
            tl1->next = tl2->next;
        carry += tl2->val;
        while (tl1->next != nullptr)
        {
            tempsum = carry + tl1->val;
            carry = tempsum / 10;
            tl1->val = tempsum % 10;
            tl1 = tl1->next;
        }
        tempsum = carry + tl1->val;
        carry = tempsum / 10;
        tl1->val = tempsum % 10;
        while (carry > 0)
        {
            tl1->next = new ListNode(carry%10);
            carry /= 10;
            tl1 = tl1->next;
        }
        return head;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        int carry(0), tempsum(0);
        auto head = new ListNode(0);
        auto tl1(l1), tl2(l2), thead(head);
        while (tl1->next != nullptr && tl2->next != nullptr)
        {
            tempsum = carry + tl1->val + tl2->val;
            carry = tempsum / 10;
            thead->val = tempsum % 10;
            tl1 = tl1->next;
            tl2 = tl2->next;
            thead->next = new ListNode(0);
            thead = thead->next;
        }
        if (tl1->next == nullptr)
            swap(tl1, tl2);
        carry += tl2->val;
        while (tl1->next!=nullptr)
        {
            tempsum = tl1->val + carry;
            carry = tempsum / 10;
            thead->val = tempsum % 10;
            thead->next = new ListNode(0);
            thead = thead->next;
            tl1 = tl1->next;
        }

        tempsum = carry + tl1->val;
        carry = tempsum / 10;
        thead->val = tempsum % 10;
        while (carry > 0)
        {
            thead->next = new ListNode(carry % 10);
            carry /= 10;
            thead = thead->next;
        }
        return head;
    }

};

int main()
{
    Solution s;
    vector<int> v1 = {9}, v2 = { 5, 6, 4, 9, 9, 9 };
    auto l1 = lc_createlist(v1, true);
    auto l2 = lc_createlist(v2, true);


    auto l3 = s.addTwoNumbers(l1, l2);
    lc_printlist(l3);

    system("pause");
    return 0;
}


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/