#include <iostream>
#include <stack>
#include <vector>
#include <queue>
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
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> re;
        if (root == NULL)
            return re;
        queue<TreeNode *> level;
        level.push(root);
        TreeNode *tmp;
        int levelsize(1);
        bool zig = false;
        while (!level.empty())
        {
            levelsize = level.size();
            vector<int> tmpv;
            while (levelsize > 0)
            {
                tmp = level.front();
                level.pop();
                tmpv.push_back(tmp->val);
                if (tmp->left != NULL)
                {
                    level.push(tmp->left);
                }
                if (tmp->right != NULL)
                {
                    level.push(tmp->right);
                }
                --levelsize;
            }
            if (zig)
                reverse(tmpv.begin(), tmpv.end());
            re.push_back(tmpv);
            zig = !zig;
        }
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
    auto re = s.zigzagLevelOrder(&root);
    for (auto rer : re)
    {
        for (auto rere : rer)
        {
            cout << rere << " ";
        }
        cout << endl;
    }
    print(&root);
    system("pause");
}