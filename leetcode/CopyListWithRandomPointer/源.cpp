#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/**
* Definition for singly-linked list with a random pointer.
*/
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};




class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        
        unordered_map<RandomListNode*, RandomListNode*> cache;
        auto newhead = new RandomListNode(head->label);
        auto tmp1 = head->next;
        auto tmp2 = newhead;
        cache[head] = newhead;
        while (tmp1 != NULL)
        {
            tmp2->next = new RandomListNode(tmp1->label);
            tmp2 = tmp2->next;
            cache[tmp1] = tmp2;
            tmp1 = tmp1->next;
        }

        tmp1 = head;
        tmp2 = newhead;

        while (tmp1 != NULL)
        {
            if (tmp1->random == NULL)
                tmp2->random = NULL;
            else
            {
                tmp2->random = cache[tmp1->random];
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        return newhead;
    }
};


int main()
{
    Solution s;
    RandomListNode head(-1);
    RandomListNode n1(-1);
    head.next = &n1;
    head.random = &n1;
    auto newhead = s.copyRandomList(&head);
    system("pause");
}