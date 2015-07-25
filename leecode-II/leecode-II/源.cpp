#include "leetcode.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

typedef _leetcode_treenode<int> TreeNode;


void testtree()
{
    int placeholder(numeric_limits<int>::max());
    vector<int> sequence = { 5, 4, 8, 11, placeholder, 4, 13, placeholder, 7, placeholder, placeholder, 1, placeholder };

    auto root = lc_deserializetree(sequence, placeholder);

    vector<int> sequence2;

    lc_serializetree(root, sequence2, placeholder);

    lc_destroytree(root);
}

void testpretraversal()
{
    vector<int> sequence = { 6, 2, 8, 0, 4, 7, 9, -1, 1, 3, 5 , 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    auto root = lc_deserializetree(sequence, -1);
    lc_bintree_preorder_r(root);
    lc_bintree_preorder_i(root);
    lc_bintree_inorder_r(root);
    lc_bintree_inorder_i(root);
    lc_bintree_postorder_r(root);
    lc_bintree_postorder_i(root);
}

int main()
{
    //testtree();
    testpretraversal();
    system("pause");
    return 0;
}