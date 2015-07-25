#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

typedef _leetcode_treenode<int> TreeNode;


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isvalid(root).legal;
    }

    bool isValidBST2(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        bool lr = _isValidBST2(root->left, numeric_limits<long long>::min(), root->val);
        bool rr = _isValidBST2(root->right, root->val, numeric_limits<long long>::max());
        return lr&&rr;
    }

private:

    bool _isValidBST2(TreeNode *root, long long minv, long long maxv)
    {
        if (root == nullptr)
            return true;
        if (root->val<minv || root->val>maxv)
            return false;
        bool lr = _isValidBST2(root->left, minv, root->val);
        bool rr = _isValidBST2(root->right, root->val, maxv);
        return lr && rr;
    }


    struct bstinfo
    {
        bool legal;
        int maxval;
        int minval;
        bstinfo(bool legal, int maxval, int minval) :
            legal(legal), 
            maxval(maxval), 
            minval(minval){};
        bstinfo(bool legal) :
            legal(legal), 
            maxval(numeric_limits<int>::max()), 
            minval(numeric_limits<int>::min()){}
        bstinfo():bstinfo(false){};
    };


    bstinfo isvalid(TreeNode *root)
    {
        if (root->left == nullptr&&root->right == nullptr)
            return bstinfo(true, root->val, root->val);
        if (root->left != nullptr && root->right != nullptr)
        {
            auto lr = isvalid(root->left);
            auto rr = isvalid(root->right);
            if (!lr.legal || !rr.legal)
                return bstinfo(false);
            return bstinfo(lr.maxval<root->val && rr.minval>root->val, rr.maxval, lr.minval);
        }
        if (root->right == nullptr)
        {
            auto lr = isvalid(root->left);
            if (!lr.legal)
                return bstinfo(false);
            return bstinfo(root->val > lr.maxval, root->val, lr.minval);
        }
        else
        {
            auto rr = isvalid(root->right);
            if (!rr.legal)
                return bstinfo(false);
            return bstinfo(root->val < rr.minval, rr.maxval, root->val);
        }
    }
};

int main()
{
    Solution s;
    //vector<int> test = { 6, 2, 8, 0, 4, 7, 9, -1, 1, 3, 5 };
    vector<int> test = { numeric_limits<int>::min(), -1, numeric_limits<int>::max()};
    auto root = lc_deserializetree(test, -1);
    cout << s.isValidBST2(root) << endl;
    cout << s.isValidBST(root) << endl;
    lc_destroytree(root);
    system("pause");
    return 0;
}