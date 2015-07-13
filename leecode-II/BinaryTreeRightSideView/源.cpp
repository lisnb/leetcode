#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


typedef _leetcode_treenode<int> TreeNode;


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> re;
        dfs(root, 1, re);
        return re;
    }
private:


    void dfs(TreeNode *root, int level, vector<int> &re)
    {
        if (root == nullptr)
            return;
        if (level > re.size())
        {
            re.push_back(root->val);
        }
        dfs(root->right, level + 1, re);
        dfs(root->left, level + 1, re);
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 3, -1, 5};
    auto root = lc_deserializetree(test, -1);
    auto re = s.rightSideView(root);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}