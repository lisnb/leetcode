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

int main()
{
    Solution s;
    vector<int> test = { 10, 5, -1, 2, 7, 1, 3, 6, 8, 0, -1, -1, -1, -1, -1,-1,9 };
    auto root = lc_deserializetree(test, -1);
    for (auto i = 1; i < 10; ++i)
        cout << s.kthSmallest(root, i) << endl;
    system("pause");
    return 0;
}