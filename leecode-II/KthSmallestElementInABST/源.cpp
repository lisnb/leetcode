#include <algorithm>
#include <iostream>
#include <vector>
#include "../leecode-II/leetcode.h"

using namespace std;

typedef _leetcode_treenode<int> TreeNode;


class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        auto tmp = root;
        while (tmp != nullptr)
        {
            stack.push_back(tmp);
            tmp = tmp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (!hasNext())
            return numeric_limits<int>::min();
        auto nextminnode = stack.back();
        stack.pop_back();
        auto tmp = nextminnode->right;
        while (tmp != nullptr)
        {
            stack.push_back(tmp);
            tmp = tmp->left;
        }
        return nextminnode->val;
    }
private:
    deque<TreeNode *> stack;
};


class Solution {
public:

    int kthSmallest(TreeNode *root, int k)
    {
        BSTIterator bst(root);
        int target(0);
        while (k-- > 0)
        {
            target = bst.next();
        }
        return target;
    }

private:

    int kthSmallestAC(TreeNode* root, int k) {
        int target(-100), ck(0);
        kthsmallest(root, k, ck, target);
        return target;
    }
private:

    void kthsmallest(TreeNode *root, int k, int &ck, int &target)
    {
        if (ck > k)
            return;
        if (root == nullptr)
            return;
        kthsmallest(root->left, k, ck, target);
        ++ck;
        if (k == ck)
            target = root->val;
        kthsmallest(root->right, k, ck, target);
    }
};

class Solution2 {
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        int ck = 0;
        TreeNode *target(nullptr);
        kthsmallest(pRoot, k, ck, target);
        return target;
    }

private:
    void kthsmallest(TreeNode *root, int k, int &ck, TreeNode *&target)
    {
        if (ck>k)
            return;
        if (root == nullptr)
            return;
        kthsmallest(root->left, k, ck, target);
        ++ck;
        if (ck == k)
        {
            target = root;
            return;
        }
        kthsmallest(root->right, k, ck, target);
    }
    void kthlargest(TreeNode *root, int k, int &ck, TreeNode *&target)
    {
        if (root == nullptr)
            return;
        kthlargest(root->right, k, ck, target);
        if (target != nullptr)
            return;
        if (ck == k)
        {
            target = root;
            return;
        }
        ++ck;
        
        kthlargest(root->left, k, ck, target);

    }

};



int main()
{
    Solution2 s;
    vector<int> test = { 8, 6, 10, 5, 7, 9, 11 };
    auto root = lc_deserializetree(test, -1);
    for (auto i = 0; i < 20; ++i)
    {
        auto re = s.KthNode(root, i);
        cout << (re == nullptr ? -1: re->val)<<endl;
    }
        //cout << s.kthSmallest(root, i) << endl;
        //cout << s.KthNode(root, i)->val << endl;
    system("pause");
    return 0;
}