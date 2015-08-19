#include <algorithm>
#include "../leecode-II/leetcode.h"
#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

typedef _leetcode_treenode<int> TreeNode;



class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
            return{};
        vector<int> prefix;
        vector<string> re;
        dfs(root, re, prefix);
        return re;
    }

private:
    void dfs(TreeNode *root, vector<string> &re, vector<int> &prefix)
    {
        if (root == nullptr)
            return;
        if (root->left==nullptr && root->right==nullptr)
        {
            stringstream ss;
            for (int i = 0; i < prefix.size(); ++i)
                ss << prefix[i] << "->";
            ss << root->val;
            re.push_back(ss.str());
            return;
        }
        prefix.push_back(root->val);
        dfs(root->left, re, prefix);
        dfs(root->right, re, prefix);
        prefix.pop_back();
    }
};


int main()
{
    Solution s;
    vector<int> test = { 1, 2, 3, -1, 5 };
    auto root = lc_deserializetree(test, -1);
    auto re = s.binaryTreePaths(root);
    for (auto r : re)
        cout << r << endl;
    unordered_set<int> tset;
    vector<int> tvec(tset.begin(), tset.end());
    system("pause");
    return 0;
}