#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


typedef _leetcode_treenode<int> TreeNode;



class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isbalance(root).first;
    }

private:

    pair<bool, int> isbalance(TreeNode *root)
    {
        if (root == nullptr)
            return make_pair<bool, int>(true, 0);
        
        auto left = isbalance(root->left);
        auto right = isbalance(root->right);

        return make_pair<bool, int>(left.first&&right.first && (abs(left.second - right.second) <= 1), max(left.second, right.second)+1);
    }
};



int main()
{
    Solution s;
    vector<int> test = { 1, 2, 3, -1, -1, 4, 5 };//, -1, -1, 6, -1
    auto root = lc_deserializetree(test, -1);
    cout << s.isBalanced(root) << endl;
    lc_destroytree(root);
    system("pause");
    return 0;
}