#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


typedef _leetcode_treenode<int> TreeNode;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> prefix;
        vector<vector<int>> re;
        if (root == nullptr)
            return re;
        path(root, sum, prefix, re);
        return re;
    }
private:

    void path(TreeNode *root, int sum, vector<int> prefix, vector<vector<int>> &re)
    {
        if (root == nullptr)
        {
            if (sum == 0)
                re.push_back(prefix);
            return;
        }
        prefix.push_back(root->val);
        path(root->left, sum - root->val, prefix, re);
        path(root->right, sum - root->val, prefix, re);
        prefix.pop_back();
    }



    void path2(TreeNode *root, int sum, vector<int> prefix, vector<vector<int>> &re)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum == root->val)
            {
                prefix.push_back(root->val);
                re.push_back(prefix);
                prefix.pop_back();
            }
            return;
        }
        prefix.push_back(root->val);
        if (root->left != nullptr)
            path2(root->left, sum - root->val, prefix, re);
        if (root->right != nullptr)
            path2(root->right, sum - root->val, prefix, re);
        prefix.pop_back();
    }
};

int main()
{
    Solution s;
    vector<int> test = { 5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1 };
    auto root = lc_deserializetree(test, -1);
    auto re = s.pathSum(root, 5);
    system("pause");
    return 0;
}