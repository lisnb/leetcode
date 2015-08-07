#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<pair<int, int>> missingranges(vector<int> nums)
    {
        if (nums.size() <= 1)
            return{};
        vector<pair<int, int>> re;
        int start, end;
        for (int i = 1; i < nums.size();++i)
        {
            if (nums.at(i) != nums.at(i - 1) + 1)
            {
                re.push_back({ nums.at(i - 1) + 1, nums.at(i) - 1});
            }
        }
        return re;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 0, 2,4, 6, 8, 10,  45, 99, 100 };
    auto re = s.missingranges(test);
    for (auto r : re)
        cout << r.first << "-" << r.second << endl;
    system("pause");
    return 0;
}