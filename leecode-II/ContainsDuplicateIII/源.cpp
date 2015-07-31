#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() || k <= 0)
            return false;
        set<int> tree;
        for (auto i = 0; i < nums.size(); ++i)
        {
            auto floor = tree.upper_bound(nums.at(i) + t);
            auto ceil = tree.lower_bound(nums.at(i) - t);
            if (floor != tree.begin())
            {
                --floor;
                if ((floor != tree.end() && *floor >= nums.at(i) || (ceil != tree.end() && *ceil <= nums.at(i))))
                    return true;
            }
            if (ceil != tree.end() && *ceil < nums.at(i))
                return true;
            tree.insert(nums.at(i));
            if (i >= k)
                tree.erase(nums.at(i - k));
        }
        return false;
    }
};


int main()
{
    Solution s;
    vector<int> test = { -1, -1 };
    cout << s.containsNearbyAlmostDuplicate(test, 1, 0) << endl;
    system("pause");
    return 0;
}