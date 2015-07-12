#include <algorithm>
#include <iostream>
#include <vector>
#include "../leecode-II/leetcode.h"

using namespace std;


typedef _leetcode_treenode<int> TreeNode;


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildtree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *buildtree(vector<int> &preorder, int pb, int pe, vector<int> &inorder, int ib, int ie)
    {
        if (ib > ie)
            return nullptr;
        if (ib == ie)
            return new TreeNode(inorder.at(ie));
        
        int ri = find(inorder.begin() + ib, inorder.begin() + ie + 1, preorder.at(pb)) - inorder.begin();

        auto root = new TreeNode(inorder.at(ri));
        root->left = buildtree(preorder, pb + 1, pb + ri - ib, inorder, ib, ri - 1);
        root->right = buildtree(preorder, pb + ri - ib + 1, pe, inorder, ri + 1, ie);
        return root;
    }
};


int main()
{
    Solution s;
    vector<int> pre = { 6, 2, 0, 4, 3, 5, 8, 7, 9 };
    vector<int> in = { 0, 2, 3, 4, 5, 6, 7, 8, 9 };

    TreeNode *root = s.buildTree(vector<int>(), vector<int>());

    lc_destroytree(root);
    system("pause");
    return 0;
}