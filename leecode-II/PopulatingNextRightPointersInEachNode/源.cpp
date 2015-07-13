#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef _leetcode_treelinknode<int> TreeLinkNode;



class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr)
            return;
        TreeLinkNode *currentlevelleft(root);
        while (currentlevelleft->left!=nullptr)
        {
            auto tmp(currentlevelleft);

            while (tmp->next != nullptr)
            {
                tmp->left->next = tmp->right;
                tmp->right->next = tmp->next->left;
                tmp = tmp->next;
            }
            tmp->left->next = tmp->right;
            currentlevelleft = currentlevelleft->left;
        }
    }
};