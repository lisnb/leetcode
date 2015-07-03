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


int main()
{
    testtree();
    system("pause");
    return 0;
}