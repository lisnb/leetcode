#include "../leecode-II/leetcode.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


typedef _leetcode_treenode<int> TreeNode;


class Solution {
public:
    int sumNumbers(TreeNode* root) {

        vector<int> nums;
        sumnumbers(root, 0, nums);
        for (auto num : nums)
            cout << num << endl;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum;
    }

private:
    void sumnumbers(TreeNode *root, int prefix, vector<int> &nums)
    {
        if (root == nullptr)
        {
            nums.push_back(0);
            return;
        }
        int nprefix = prefix * 10 + root->val;
        if (root ->left==nullptr && root->right == nullptr)
        {
            nums.push_back(nprefix);
            return;
        }
        if (root->left!=nullptr)    
            sumnumbers(root->left, nprefix, nums);
        if (root->right!=nullptr)
            sumnumbers(root->right, nprefix, nums);
    }
};


int main()
{
    Solution s;
    vector<int> seq = { 1, 2, 3, -1, 4 };
    auto root = lc_deserializetree(seq, -1);
    auto re = s.sumNumbers(root);
    lc_destroytree(root);
    cout << re << endl;
    system("pause");
    return 0;
}