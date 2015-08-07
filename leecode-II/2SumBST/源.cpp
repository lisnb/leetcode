#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef _leetcode_treenode<int> TreeNode;

class Solution
{
public:
    vector<pair<int, int> > twosum(TreeNode *root, int target)
    {
        vector<pair<int, int> > re;
        deque<TreeNode *> minstack, maxstack;
        pushleft(minstack, root);
        pushright(maxstack, root);
        TreeNode *left = minstack.back();
        minstack.pop_back();
        pushleft(minstack, left->right);
        TreeNode *right = maxstack.back();
        maxstack.pop_back();
        pushright(maxstack, right->left);
        while (left->val < right->val && left != right)
        {
            if (left->val + right->val == target)
            {
                re.push_back({ left->val, right->val });
                left = minstack.back();
                minstack.pop_back();
                pushleft(minstack, left->right);
                right = maxstack.back();
                maxstack.pop_back();
                pushright(maxstack, right->left);
            }
            else if (left->val + right->val > target)
            {
                right = maxstack.back();
                maxstack.pop_back();
                pushright(maxstack, right->left);
            }
            else
            {
                left = minstack.back();
                minstack.pop_back();
                pushleft(minstack, left->right);
            }
        }
        return re;
    }

private:
    void pushleft(deque<TreeNode *> &stack, TreeNode *root)
    {
        auto t(root);
        while (t != nullptr)
        {
            stack.push_back(t);
            t = t->left;
        }
    }

    void pushright(deque<TreeNode *> &stack, TreeNode *root)
    {
        auto t(root);
        while (t != nullptr)
        {
            stack.push_back(t);
            t = t->right;
        }
    }
};



int main()
{
    Solution s;
    vector<int> seq = { 6, 2, 8, 0, 4, 7, 9, -1, 1, 3, 5 };
    auto root = lc_deserializetree(seq, -1);
    auto re = s.twosum(root, 15);
    for (auto r : re)
        cout << r.first << " " << r.second << endl;
    system("pause");
    return 0;
}