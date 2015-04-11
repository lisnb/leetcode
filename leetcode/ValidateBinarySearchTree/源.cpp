#include <vector>
#include <iostream>
#include <limits>
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

struct Result{
    bool isbst;
    int max;
    int min;
    Result(bool isbst, int max, int min) :isbst(isbst), max(max), min(min){}
    Result(){}
};

class Solution {
public:
    /*bool isValidBSTWA(TreeNode *root) {
        if (root == NULL)
            return false;
        int lv(numeric_limits<int>::min()), rv(numeric_limits<int>::max());
        bool bl(true), br(true);
        if (root->left != NULL)
        {
            lv = root->left->val;
            bl = isValidBST(root->left);
        }
        if (root->right != NULL)
        {
            rv = root->right->val;
            br = isValidBST(root->right);
        }
        return bl && br && lv<root->val && rv>root->val;
    }*/
    bool isValidBST(TreeNode *root)
    {
        return isValidBSTR(root).isbst;
    }

    Result isValidBSTR(TreeNode *root)
    {
        if (root == NULL)
            return Result(true, numeric_limits<int>::min(), numeric_limits<int>::max());
        Result r(true, root->val, root->val);

        if (root->left != NULL)
        {
            Result lr = isValidBSTR(root->left);
            r.isbst = (r.isbst && lr.isbst && root->val > lr.max);
            r.min = lr.min;
        }
        
        if (root->right != NULL)
        {
            Result rr = isValidBSTR(root->right);
            r.isbst = (r.isbst && rr.isbst && root->val < rr.min);
            r.max = rr.max;
        }

        return r;
    }
};