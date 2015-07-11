#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;


typedef _leetcode_treenode<int> TreeNode;


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return issymmetric(root);
        //return issymequal(root->left, root->right);
    }

private:

    bool issymequal(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return issymequal(left->left, right->right) && issymequal(left->right, right->left);
    }

    bool issymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        deque<TreeNode *> queue;
        queue.push_back(root->left);
        queue.push_back(root->right);
        int levelsize(0);
        while (!queue.empty())
        {
            levelsize = queue.size();
            while (levelsize > 0)
            {
                TreeNode *l = queue.front();
                queue.pop_front();
                TreeNode *r = queue.front();
                queue.pop_front();
                levelsize -= 2;
                if (l == nullptr&&r == nullptr)
                    continue;
                if (l == nullptr || r == nullptr)
                    return false;
                if (l->val != r->val)
                    return false;
                queue.push_back(l->left);
                queue.push_back(r->right);
                queue.push_back(l->right);
                queue.push_back(r->left);
            }
        }
        return true;
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 2, -1, 3, 3 };
    auto root = lc_deserializetree(test, -1);
    cout << s.isSymmetric(root) << endl;
    system("pause");
    return 0; 
}