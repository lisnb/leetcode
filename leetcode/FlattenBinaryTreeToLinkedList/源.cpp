#include <iostream>
#include <vector>

using namespace std;



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
    void flatten(TreeNode *root) {
        flattenchildtree(root);
    }

    TreeNode *flattenchildtree(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
            return root;
        if (root->left == NULL)
        {
            return flattenchildtree(root->right);
        }
        if (root->right == NULL)
        {
            root->right = root->left;
            root->left = NULL;
            return flattenchildtree(root->right);
        }
        TreeNode *l = flattenchildtree(root->left);
        l->right = root->right;
        TreeNode *r = flattenchildtree(root->right);
        root->right = root->left;
        root->left = NULL;
        return r;
    }
};


void print(TreeNode *root)
{
    TreeNode *tmp = root;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->right;
    }
    cout << endl;
}

int main()
{
    Solution s;
    TreeNode root(1);
    TreeNode l(2);
    TreeNode r(3);
    TreeNode ll(4), lr(5), rl(6), rr(7);
    l.left = &ll;
    l.right = &lr;
    r.left = &rl;
    r.right = &rr;
    root.left = &l;
    root.right = &r;
    s.flatten(&root);
    print(&root);
    system("pause");
}