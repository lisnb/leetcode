#include <iostream>
#include <queue>
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> re;
        if (root == NULL)
            return re;
        queue<TreeNode *> level;
        level.push(root);
        TreeNode *tmp;
        while (!level.empty())
        {
            int levelsize = level.size();
            while (levelsize > 0)
            {
                tmp = level.front();
                level.pop();
                --levelsize;
                if (levelsize == 0)
                    re.push_back(tmp->val);
                if (tmp->left)
                    level.push(tmp->left);
                if (tmp->right)
                    level.push(tmp->right);
            }
        }
        return re;
    }
};


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
    //r.right = &rr;
    root.left = &l;
    root.right = &r;
    auto re = s.rightSideView(&root);
        for (auto rere : re)
        {
            cout << rere << " ";
        }
        cout << endl;
    system("pause");
}