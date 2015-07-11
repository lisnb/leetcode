#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


typedef _leetcode_treenode<int> TreeNode;



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr)
            return nullptr;
        if (p->val == q->val)
            return p;
        if (p == root || q == root)
            return root;
        if (p->val > q->val)
            swap(p, q);
        auto t(root);
        while (t!=nullptr)
        {
            if (t == p || t==q)
                return t;
            if (t->val > p->val && t->val < q->val)
                return t;
            else if (t->val > q->val)
                t = t->left;
            else
                t = t->right;
        }
        return root;
    }
};