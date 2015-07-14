#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;



//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return node;
        if (edges.find(node->label) == edges.end())
        {
            edges[node->label] = new UndirectedGraphNode(node->label);
            for (auto e : node->neighbors)
            {
                edges[node->label]->neighbors.push_back(cloneGraph(e));
            }
        }
        return edges[node->label];

    }

    UndirectedGraphNode *cloneGraphBFS(UndirectedGraphNode *node){
        if (!node)
            return node;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        UndirectedGraphNode *temp;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (edges.find(temp->label) == edges.end())
                for (auto e : temp->neighbors)
                {
                    //visit(e);
                    q.push(e);
                }
        }
        return edges[node->label];
    }
private:
    unordered_map<int, UndirectedGraphNode*> edges;
};


int main()
{
    Solution s;

    system("pause");
}