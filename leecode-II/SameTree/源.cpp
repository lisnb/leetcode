#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


typedef _leetcode_treenode<int> TreeNode;


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

private:
    bool isSubTree(TreeNode *p, TreeNode *q)
    {
        if (q == nullptr)
            return true;
        return ismatch(p, q);
    }

    bool ismatch(TreeNode *p, TreeNode *q)
    {
        if (isSameTree(p, q))
            return true;
        return ismatch(p->left, q) && ismatch(p->right, q);
    }
};