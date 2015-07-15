#include "../leecode-II/leetcode.h"
#include <iostream>
using namespace std;

typedef _leetcode_treenode<int> TreeNode;



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr)
            return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr&&right != nullptr)
            return root;
        else
            return left == nullptr ? right : left;
    }
};