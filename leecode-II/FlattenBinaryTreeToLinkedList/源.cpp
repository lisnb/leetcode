#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



typedef _leetcode_treenode<int> TreeNode;


class Solution {
public:
    void flatten(TreeNode* root) {
        subflatten(root);
    }

private:
    TreeNode *subflatten(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        auto tmpright = root->right;
        auto left = subflatten(root->left);
        auto right = subflatten(root->right);
        if (left == nullptr && right == nullptr)
            return root;
        if (left == nullptr)
            return right;
        if (right == nullptr)
        {
            root->right = root->left;
            root->left = nullptr;
            return left;
        }
        root->right = root->left;
        left->right = tmpright;
        root->left = nullptr;
        return right;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 5, 3, 4, -1, 6 };
    auto root = lc_deserializetree(test, -1);
    s.flatten(root);
    lc_destroytree(root);
    system("pause");
    return 0;
}