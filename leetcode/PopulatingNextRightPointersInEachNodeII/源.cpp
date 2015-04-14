#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;



/**
* Definition for binary tree with next pointer.
*/
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        auto cur = root;
        while (cur)
        {
            auto next = cur->left==NULL? cur->right :cur->left;
            while (cur)
            {
                if (cur->left)
                {
                    if (cur->right)
                    {
                        cur->left->next = cur->right;
                    }
                    else
                    {

                    }
                }
                    
                if (cur->right)
                    cur->right->next = cur->next ? cur->next->left : NULL;
                cur = cur->next;
            }
            cur = next;
        }
    }
    void TLE(TreeLinkNode *root) {
        if (root == NULL)
            return;
        queue<TreeLinkNode *> level;
        level.push(root);
        TreeLinkNode *levelhead, *tmp;
        int levelsize(0);
        int childnum(0);
        while (!level.empty())
        {
            levelsize = level.size();
            levelhead = level.front();
            level.pop();
            if (levelhead->left != NULL)
                level.push(levelhead->left);
            if (levelhead->right != NULL)
                level.push(levelhead->right);
            --levelsize;
            if (levelsize==0)
                continue;
            while (levelsize > 0)
            {
                tmp = level.front();
                level.pop();
                levelhead->next = tmp;
                levelhead = tmp;
                if (levelhead->left != NULL)
                    level.push(levelhead->left);
                if (levelhead->right != NULL)
                    level.push(levelhead->right);
                --levelsize;
            }
        }
    }
};

int main()
{
    Solution s;
    TreeLinkNode root(1);
    TreeLinkNode l(2);
    TreeLinkNode r(3);
    TreeLinkNode ll(4), lr(5), rl(6), rr(7);
    l.left = &ll;
    l.right = &lr;
    //r.left = &rl;
    //r.right = &rr;
    root.left = &l;
    root.right = &r;
    s.TLE(&root);
    
    cout << endl;
    system("pause");
}