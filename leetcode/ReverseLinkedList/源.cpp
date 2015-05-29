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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        auto nhead = head;
        reverselist(head, nhead);
        return nhead;
    }

private:
    ListNode *reverselist(ListNode *head, ListNode *&nhead)
    {
        if (head->next == NULL)
        {
            nhead = head;
            return head;
        }
        auto t = head->next;
        head->next = NULL;
        auto tt = reverselist(t, nhead);
        tt->next = head;
        return head;
    }
};



ListNode *createlist(vector<int> nums)
{
    if (nums.empty())
        return NULL;
    auto head = new ListNode(nums.at(0));
    auto thead = head;
    for (auto i = 1; i < nums.size(); ++i)
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
    vector<int> test = { 1,2 };
    auto head = createlist(test);
    print(head);
    auto nhead = s.reverseList(head);
    print(nhead);
    destroylist(nhead);
    system("pause");

}