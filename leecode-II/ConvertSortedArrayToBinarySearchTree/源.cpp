#include <algorithm>
#include <iostream>
#include "../leecode-II/leetcode.h"
#include <vector>

using namespace std;

typedef _leetcode_treenode<int> TreeNode;


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return atobst(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *atobst(vector<int> &nums, int  bi, int ei)
    {
        if (bi<ei)
            return nullptr;
        if (bi == ei)
        {
            auto t = new TreeNode(nums.at(bi));
            return t;
        }
        else
        {
            int mid = bi + (ei - bi) / 2;
            auto root = new TreeNode(nums.at(mid));
            root->left = atobst(nums, bi, mid - 1);
            root->right = atobst(nums, mid + 1, ei);
            return root;
        }

    }
};