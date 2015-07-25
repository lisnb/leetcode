#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        if (numCourses == 0)
            return{};
        vector<vector<int>> lessons(numCourses);
        vector<int> flags(numCourses, 0);
        for (auto pre : prerequisites)
            lessons.at(pre.first).push_back(pre.second);
        vector<int> re;
        for (auto i = 0; i < numCourses; ++i)
        {
            if (flags.at(i) == 0)
            {
                if (!dfs(lessons, flags, re, i))
                    return{};
            }
        }
        return re;
    }
    vector<int> findOrderAC(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0)
            return{};
        vector<vector<int>> lessons(numCourses);
        vector<int> flags(numCourses, 0);
        for (auto pre : prerequisites)
            lessons.at(pre.first).push_back(pre.second);
        vector<int> re;
        for (auto i = 0; i < numCourses; ++i)
        {
            if (flags.at(i) == 0)
            {
                if (!bfs(lessons, flags, re, i))
                    return {};
            }
        }
        return re;
    }

private:
    bool dfs(vector<vector<int>> &lessons, vector<int> &flags, vector<int> &re, int cur)
    {
        flags.at(cur) = 1;
        for (auto pre : lessons.at(cur))
        {
            if (flags.at(pre) == 1)
                return false;
            if (flags.at(pre) == 0)
                if (!dfs(lessons, flags, re, pre))
                    return false;
        }
        flags.at(cur) = 2;
        re.push_back(cur);
        return true;

    }
    bool bfs(vector<vector<int>> &lessons, vector<int> &flags, vector<int> &re, int cur)
    {
        flags.at(cur) = 1;
        for (auto pre : lessons.at(cur))
        {
            if (flags.at(pre) == 1)
                return false;
            if (flags.at(pre) == 0)
                if (!bfs(lessons, flags, re, pre))
                    return false;
        }
        flags.at(cur) = 2;
        re.push_back(cur);
        return true;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int>> prerequisites = {
        { 1, 0 },/* { 2, 0 }, { 3, 1 }, { 3, 2 }, */{0, 1}
    };
    auto re = s.findOrder(2, prerequisites);
    for (auto t : re)
        cout << t << endl;
    system("pause");
    return 0;
}