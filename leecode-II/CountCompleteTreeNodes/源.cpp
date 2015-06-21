#include <iostream>
#include <vector>
#include <queue>


using namespace std;


/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    int countNodesTLE(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int cnt = 0;
        auto tmp(root);
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            ++cnt;
            if (tmp->left == NULL)
                return 2*(cnt-1)+1;
            if (tmp->right == NULL)
                return 2 *cnt;
            q.push(tmp->left);
            q.push(tmp->right);
        }
    }


    int countNodes(TreeNode *root){
        if (root == NULL)
            return 0;
        int lh(0), rh(0);
        for (auto p = root; p; p = p->left) ++lh;
        for (auto p = root; p; p = p->right) ++rh;
        if (lh == rh)
            return (1 << lh) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main()
{
    cout << (1 << 3) << endl;
    system("pause");
    return 0;
}