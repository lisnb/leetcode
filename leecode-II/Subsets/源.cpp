#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> re;
        //vector<int> prefix;
        //subset(nums, 0, prefix, re);
        subset(nums, re);
        return re;
    }
private:
    void subset(const vector<int> &nums, vector<vector<int>> &re)
    {
        re.reserve(1 << nums.size());
        re.push_back({});
        for (auto num : nums)
        {
            int csize = re.size();
            copy(re.begin(), re.begin() + csize, back_inserter(re));
            for (auto i = csize; i < re.size(); ++i)
            {
                re.at(i).push_back(num);
            }
        }
    }

    void subset(const vector<int> &nums, int ci, vector<int> &prefix, vector<vector<int>> &re)
    {

        re.push_back(prefix);
        if (ci == nums.size())
            return;
        for (auto i = ci; i < nums.size(); ++i)
        {
            prefix.push_back(nums.at(i));
            subset(nums, i + 1, prefix, re);
            prefix.pop_back();
            while (i + 1 < nums.size() && nums.at(i) == nums.at(i + 1))
                ++i;
        }
    }
};


int main()
{
    Solution s;
    vector<int> test = {  };
    auto re = s.subsets(test);
    cout << "cnt: " << re.size() << endl;
    for (auto r : re)
    {
        for (auto rr : r)
            cout << rr << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}