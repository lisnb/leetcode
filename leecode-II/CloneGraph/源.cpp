#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


typedef _leetcode_undirectedgraphnode<int> UndirectedGraphNode;


class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        if (cache.find(node->label) == cache.end())
        {
            cache[node->label] = new UndirectedGraphNode(node->label);
            for (auto nei : node->neighbors)
            {
                cache[node->label]->neighbors.push_back(cloneGraph(nei));
            }
        }
        return cache[node->label];

    }
private:
    unordered_map<int, UndirectedGraphNode *> cache;
};