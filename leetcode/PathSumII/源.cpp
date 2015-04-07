#include <iostream>
#include <vector>

using namespace std;




//Definition for binary tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        pathSum(root, sum, vector<int>());
        return re;
    }
    void pathSum(TreeNode *root, int sum, vector<int> prefix)
    {
        if (!root)
            return;
        if (!root->left && !root->right){
            if (sum == root->val)
            {
                prefix.push_back(root->val);
                re.push_back(prefix);
                prefix.pop_back();
            }
        }
        prefix.push_back(root->val);
        if (root->left)
            pathSum(root->left, sum - root->val, prefix);
        if (root->right)
            pathSum(root->right, sum - root->val, prefix);
        prefix.pop_back();
    }

private:
    vector<vector<int> > re;
};


