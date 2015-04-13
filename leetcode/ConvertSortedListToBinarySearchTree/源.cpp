#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
* Definition for binary tree
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        vector<int> num;
        ListNode *tmp = head;
        while (tmp != NULL)
        {
            num.push_back(tmp->val);
            tmp = tmp->next;
        }
        return sortedArrayToBST(num);
    }
private:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size() - 1);
    }
    TreeNode *sortedArrayToBST(vector<int> &num, int b, int s)
    {
        if (b > s)
            return NULL;
        if (b == s)
            return new TreeNode(num.at(b));
        int pivot = (b + s) / 2;
        TreeNode *root = new TreeNode(num.at(pivot));
        root->left = sortedArrayToBST(num, b, pivot - 1);
        root->right = sortedArrayToBST(num, pivot + 1, s);
        return root;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> tests = {
        { 1, 2, 3, 4, 5, 6, 7 },
        { 1, 2, 3 },
        { 1, 2 },
        { 1 }
    };
    for (auto t : tests)
    {
        auto tre = s.sortedArrayToBST(t);
    }
    system("pause");
}