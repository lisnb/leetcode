#include "../leecode-II/leetcode.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


typedef _leetcode_randomlistnode<int> RandomListNode;

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)
            return head;
        RandomListNode *p1(head), *tmp(nullptr);
        
        //duplicate it
        while (p1 != nullptr)
        {
            tmp = p1->next;
            p1->next = new RandomListNode(p1->label);
            p1->next->next = tmp;
            p1 = tmp;
        }

        //add random
        p1 = head;
        while (p1 != nullptr)
        {
            if (p1->random != nullptr)
                p1->next->random = p1->random->next;
            p1 = p1->next->next;
                
        }

        //extract 
        RandomListNode *newhead(head->next), *p2(nullptr);
        p1 = head;
        p2 = newhead;
        while (p2->next != nullptr)
        {
            p1->next = p2->next;
            p1 = p1->next;
            p2->next = p1->next;
            p2 = p2->next;
        }
        p1->next = nullptr;
        return newhead; 
    }
};



class Solution2 {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        auto thead(pHead);
        while (thead != nullptr)
        {
            auto t = new RandomListNode(thead->label);
            t->next = thead->next;
            thead->next = t;
            thead = t->next;
        }

        thead = pHead;
        while (thead != nullptr)
        {
            if (thead->random!=nullptr)
                thead->next->random = thead->random->next;
            thead = thead->next->next;
        }

        auto newhead = new RandomListNode(0);
        auto p1(pHead), p2(newhead);
        while (p1 != nullptr)
        {
            p2->next = p1->next;
            p2 = p2->next;
            p1->next = p2->next;
            p1 = p1->next;
        }
        p2->next = nullptr;
        return newhead->next;

    }
};


int main()
{
    Solution s;
    RandomListNode r1(3), r2(4);
    r1.next = &r2;
    s.copyRandomList(&r1);
    system("pause");
    return 0;
}