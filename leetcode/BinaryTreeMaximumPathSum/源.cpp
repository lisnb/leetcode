#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

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
    int maxPathSum(TreeNode *root) {
        if (root == NULL)
            return 0;
        int maxps = numeric_limits<int>::min();

        int maxps2 = maxpathsum(root, maxps);
        return max(maxps2, maxps);

    }
private:
    int maxpathsum(TreeNode *root, int &maxps)
    {
        int lmps(0), rmps(0);
        if (root->left == NULL && root->right == NULL)
            return root->val;
        if (root->left)
            lmps = maxpathsum(root->left, maxps);
        if (root->right)
            rmps = maxpathsum(root->right, maxps);

        maxps = max({ lmps + rmps + root->val, maxps, root->left == NULL ? numeric_limits<int>::min() : lmps, root->right == NULL ? numeric_limits<int>::min() : rmps });

        return max({ root->val, root->val + rmps, root->val + lmps });
    }
};


int main()
{
    Solution s;
    TreeNode root(2);
    TreeNode l(-1);
    TreeNode r(-2);
    TreeNode ll(-4), lr(-5), rl(6), rr(7);
    /*l.left = &ll;
    l.right = &lr;
    r.left = &rl;
    r.right = &rr;*/
    root.left = &l;
    root.right = &r;

    //root.right = &l;
    /*l.right = &r;
    r.right = &ll;
    ll.right = &lr;*/
    cout << s.maxPathSum(&root) << endl;

    cout << endl;
    system("pause");
}