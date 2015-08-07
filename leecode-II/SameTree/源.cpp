#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


typedef _leetcode_treenode<int> TreeNode;


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubTree(TreeNode *p, TreeNode *q)
    {
        if (q == nullptr)
            return true;
        return ismatch(p, q);
    }

private:
    bool ismatch(TreeNode *p, TreeNode *q)
    {
        if (isSameTree(p, q))
            return true;
        return ismatch(p->left, q) && ismatch(p->right, q);
    }
};


class Solution2 {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr)
            return false;
        return ismatch(pRoot1, pRoot2);
    }

    bool ismatch(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr)
            return false;
        if (issubtree(root1, root2))
            return true;
        return ismatch(root1->left, root2) || ismatch(root1->right, root2);

    }

private:
    bool issubtree(TreeNode *root1, TreeNode *root2)
    {
        if (root2 == nullptr)
            return true;
        if (root1 == nullptr)
            return false;
        if (root1->val != root2->val)
            return false;
        return issubtree(root1->left, root2->left) && issubtree(root1->right, root2->right);
    }
};
int main()
{
    Solution2 s;
    vector<int> t1 = { 8, 8, 7, 9, 2, -1, -1, -1, -1, 4, 7 };
    vector<int> t2 = { 8, 9, 2 };
    auto r1 = lc_deserializetree(t1, -1);
    auto r2 = lc_deserializetree(t2, -1);
    cout << s.HasSubtree(r1, r2) << endl;
    system("pause");
    return 0;
}