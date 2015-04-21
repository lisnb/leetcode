#include <vector>
#include <algorithm>
#include <iostream>

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists.at(0);
        int index = 0;
        int listlen = lists.size();
        while (index != 1)
        {
            index = 0;
            for (auto i = 0; i < listlen; i+=2, ++index)
            {
                if (i + 1 == listlen)
                {
                    lists.at(index) = lists.at(i);
                }
                else
                {
                    lists.at(index) = merge2lists(lists.at(i), lists.at(i + 1));
                }
            }
            listlen = (listlen + 1) / 2;
        }
        return lists.at(0);
    }
private:
    ListNode *merge2lists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL&&l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *head;
        if (l1->val > l2->val)
        {
            head = l2;
            l2 = l2->next;
        }
        else
        {
            head = l1;
            l1 = l1->next;
        }
        auto thead = head;
        while (l1 != NULL&&l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                thead->next = l2;
                l2 = l2->next;
            }
            else
            {
                thead->next = l1;
                l1 = l1->next;
            }
            thead = thead->next;
            //thead->next = NULL;
        }
        thead->next = l1 == NULL ? l2 : l1;
        return head;
    }
};


ListNode *createlist(vector<int> nums)
{
    if (nums.empty())
        return NULL;
    auto head = new ListNode(nums.at(0));
    auto thead = head;
    for (auto i = 1; i < nums.size();++i)
    {
        thead->next = new ListNode(nums.at(i));
        thead = thead->next;
    }
    return head;
}

void destroylist(ListNode *list)
{
    auto head = list;
    while (head != NULL)
    {
        list = list->next;
        delete head;
        head = list;
    }
}

void print(ListNode *list)
{
    auto head = list;
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> l1v = { 1,3,5,7,9 };
    vector<int> l2v = { 0, 2, 4, 6, 8, 10, 12 };
    vector<int> l3v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> l4v = { 100, 200, 300, 400 };
    vector<int> l5v = { -1 };
    
    auto l1 = createlist(l1v);
    auto l2 = createlist(l2v);
    auto l3 = createlist(l3v);
    auto l4 = createlist(l4v);
    auto l5 = createlist(l5v);


    vector<ListNode *> test = { l1, l2, l3, l4, l5 };

    auto ml3 = s.mergeKLists(test);

    print(ml3);


    //destroylist(l1);
    //destroylist(l2);
    destroylist(ml3);
    system("pause");
}