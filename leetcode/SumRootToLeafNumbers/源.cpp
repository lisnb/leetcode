#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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
    struct result{
        int fac;
        int val;
    };
public:
    int sumNumbers(TreeNode *root) {
        dfs(root, 0);
        int r(0);
        for (auto n : nums)
        {
            cout << n << endl;
            r += n;
        }
        return r;
    }

    void dfs(TreeNode *root, int carry)
    {
        if (!root->left && !root->right)
        {
            nums.push_back(carry*10+root->val);
            return;
        }
        if (root->left)
        {
            dfs(root->left, carry * 10 + root->val);
        }
        if (root->right)
        {
            dfs(root->right, carry * 10 + root->val);
        }
    }

    vector<int> nums;

    /*int sumNumbers(TreeNode *root, int carry)
    {
        if (!root->left && !root->right)
            return carry;


    }

    result sumnumbers(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            result tr = { 1, root->val };
            return tr;
        }
        result ls, rs;
        
        if (root->left)
            ls = sumnumbers(root->left);
        else
        {
            ls.fac = 0;
            ls.val = 0;
        }
        if (root->right)
            rs = sumnumbers(root->right);
        else
        {
            rs.fac = 0;
            rs.val = 0;
        }
        int val = root->val * 10 * ls.fac + ls.val + root->val * 10 * rs.fac + rs.val;
        int fac = ls.fac > rs.fac ? ls.fac : rs.fac;
        fac *= 10;
        result r = { fac, val };
        return r;
    }*/
};


int main()
{
    Solution s;
    TreeNode *root = new TreeNode(9);
    //root->left = new TreeNode(8);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(5);
    cout << s.sumNumbers(root) << endl;

    system("pause");
}