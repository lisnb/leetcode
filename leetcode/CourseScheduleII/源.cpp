#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> re;
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> colors(numCourses, 0);
        for (auto pre : prerequisites)
            graph.at(pre.first).push_back(pre.second);
        for (auto i = 0; i < numCourses; ++i)
        {
            if (colors[i] == 0)
            {
                bool tmp = dfs(graph, colors, i, re);
                if (!tmp)
                    return vector<int>();
            }
        }
        return re;
    }


    bool dfs(const vector<vector<int>> &graph, vector<int> &colors, int start, vector<int> &re)
    {
        colors[start] = 1;
        for (auto i : graph.at(start))
        {
            if (colors[i] == 1)
                return false;
            if (colors[i] == 0)
            {
                bool tmp = dfs(graph, colors, i, re);
                if (!tmp)
                    return false;
            }
        }
        colors[start] = 2;
        re.push_back(start);
        return true;
    }
};



int main()
{
    Solution s;
    vector<pair<int, int>> tests = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };
    auto re = s.findOrder(4, tests);
    for (auto r : re)
        cout << r;
    cout << endl;
    system("pause");
}