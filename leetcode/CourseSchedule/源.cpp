#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // 0: white, has not been visited yet
        // 1: gray, is being visiting
        // 2: black, has been visited already
        vector<int> colors(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto pre : prerequisites)
            graph[pre[0]].push_back(pre[1]);
        bool tmp(true);
        for (auto i = 0; i < numCourses; ++i)
        {
            if (colors[i] == 0)
            {
                tmp = dfs(graph, colors, i);
                if (!tmp)
                    return false;
            }
        }
        return true;

    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        // 0: white, has not been visited yet
        // 1: gray, is being visiting
        // 2: black, has been visited already
        vector<int> colors(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto pre : prerequisites)
            graph[pre.first].push_back(pre.second);
        bool tmp(true);
        for (auto i = 0; i < numCourses; ++i)
        {
            if (colors[i] == 0)
            {
                tmp = dfs(graph, colors, i);
                if (!tmp)
                    return false;
            }
        }
        return true;

    }

    bool dfs(const vector<vector<int>> &graph, vector<int> &colors, int start)
    {
        colors[start] = 1;
        bool tmp;
        for (auto i : graph[start])
        {
            if (colors[i] == 1)
                return false;
            if (colors[i] == 0)
            {
                tmp = dfs(graph, colors, i);
                if (!tmp)
                    return false;
            }
        }
        colors[start] = 2;
        return true;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> test = {
        {0,1},
        {1,0}
    };

    cout << s.canFinish(2, test) << endl;
    system("pause");

}

