#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;


typedef _leetcode_treenode<int> TreeNode;



void bst_insert(TreeNode *root, int num)
{
    if (root == nullptr)
    {
        root = new TreeNode(num);
        return;
    }
    auto troot(root);
    while (true)
    {
        if (troot->val == num)
            return;
        else if (troot->val > num)
        {
            if (troot->left == nullptr)
            {
                troot->left = new TreeNode(num);
                return;
            }
            else
                troot = troot->left;
        }
        else
        {
            if (troot->right == nullptr)
            {
                troot->right = new TreeNode(num);
                return;
            }
            else
                troot = troot->right;
        }
    }
}


void bst_delete(TreeNode *root, int num)
{
    if (root == nullptr)
        return;
    TreeNode *p(root), *pp(nullptr);
    while (p != nullptr && p->val != num)
    {
        pp = p;
        p = p->val > num ? p->left : p->right;
    }
    if (p == nullptr)
        return;
    if (p->left != nullptr && p->right != nullptr)
    {
        TreeNode *s(p->left), *ps(p);
        while (s->right != nullptr)
        {
            ps = s;
            s = s->right;
        }
        p->val = s->val;
        p = s;
        pp = ps;
    }
    
    TreeNode *c(p->left != nullptr ? p->left : p->right);
    if (p == root)
        root = c;
    else
    {
        if (p == pp->left)
            pp->left = c;
        else
            pp->right = c;
    }
    delete p;
}


void bst_delete2(TreeNode *root, int num)
{
    if (root == nullptr)
        return;
    TreeNode *p(root), *pp(nullptr);
    while (p != nullptr && p->val != num)
    {
        pp = p;
        p = p->val > num ? p->left : p->right;
    }
    if (p == nullptr)
        return;
    if (p->left != nullptr && p->right != nullptr)
    {
        TreeNode *s(p->left), *ps(p);
        while (s->right != nullptr)
        {
            ps = s;
            s = s->right;
        }
        p->val = s->val;
        p = s;
        pp = ps;
    }

    TreeNode *c(p->left == nullptr ? p->right : p->left);
    if (p == root)
        root = c;
    else
    {
        if (p == pp->left)
            pp->left = c;
        else
            pp->right = c;
    }
    delete p;
}

int main()
{
    vector<int> test = { 6, 2, 8, 0, 4, 7, 9, -1, 1, 3, 5 };
    auto root = lc_deserializetree(test, -1);
    bst_delete(root, 2);
    system("pause");
    return 0;
}