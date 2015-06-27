#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> re = { -1, -1 };
        if (nums.empty())
            return re;
        search(nums, target, 0, nums.size() - 1, re.at(0), re.at(1));
        return re;
    }
private:
    void search(const vector<int> &nums, int target, int b, int e, int &lb, int &ub)
    {
        if (b > e || (b==e && nums.at(b)!=target))
        {
            //lb = numeric_limits<int>::max();
            //ub = numeric_limits<int>::min();
            lb = -1;
            ub = -1;
            return;
        }
        if (b == e && nums.at(b) == target)
        {
            lb = b;
            ub = b;
            return;
        }

        int mid = b + (e - b) / 2;
        if (nums.at(mid) == target)
        {
            int llb(0), lub(0), rlb(0), rub(0);
            search(nums, target, b, mid - 1, llb, lub);
            search(nums, target, mid + 1, e, rlb, rub);
            lb = llb == -1 ? mid : llb;// min(mid, llb);
            ub = rub == -1 ? mid : rub;// max(rub, mid);
        }
        else if (nums.at(mid) > target)
        {
            search(nums, target, b, mid - 1, lb, ub);
        }
        else
        {
            search(nums, target, mid + 1, e, lb, ub);
        }
    }
};


int main()
{
    Solution s;
    vector<int> test = { 5, 7, 7, 8, 8, 10 };
    auto re = s.searchRange(test, 9);
    cout << re.at(0) << " " << re.at(1) << endl;
    system("pause");
    return 0;
}