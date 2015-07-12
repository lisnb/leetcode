#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


typedef _leetcode_treenode<int> TreeNode;



class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildtree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *buildtree(vector<int> &postorder, int pb, int pe, vector<int> &inorder, int ib, int ie)
    {
        if (ib > ie)
            return nullptr;
        if (ib == ie)
            return new TreeNode(inorder.at(ie));

        int ri = find(inorder.begin() + ib, inorder.begin() + ie + 1, postorder.at(pe)) - inorder.begin();
        auto root = new TreeNode(inorder.at(ri));
        root->left = buildtree(postorder, pb, pb + ri - ib - 1, inorder, ib, ri - 1);
        root->right = buildtree(postorder, pb + ri - ib, pe - 1, inorder, ri + 1, ie);
        return root;
    }
};