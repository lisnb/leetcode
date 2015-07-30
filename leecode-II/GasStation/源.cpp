#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

using namespace std;





class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int gassum(0), costsum(0);
        int tank(0), start(0);
        for (int i = 0; i < gas.size(); ++i)
        {
            gassum += gas.at(i);
            costsum += cost.at(i);
            tank += (gas.at(i) - cost.at(i));
            if (tank < 0)
            {
                tank = 0;
                start = i + 1;
            }
        }
        return gassum < costsum ? -1 : start;
    }

    int canCompleteCircuitWA(vector<int>& gas, vector<int>& cost) {
        if (gas.empty())
            return 0;
        vector<int> remain(gas.size(), 0);
        for (auto i = 0; i < gas.size(); ++i)
            remain.at(i) = gas.at(i) - cost.at(i);
        
        auto sum = accumulate(remain.begin(), remain.end(), 0);

        if (sum < 0)
            return -1;
        auto index = imaxsubsum(remain);
        return index%gas.size();
        
    }


private:

    int imaxsubsum(vector<int> &nums)
    {
        int tstart(0), tmaxsum(0);
        int maxsum(numeric_limits<int>::min()), start(0);
        for (auto i = 0; i < nums.size(); ++i)
        {
            tmaxsum += nums.at(i);
            cout << tmaxsum << " " << maxsum << endl;
            if (tmaxsum > maxsum)
            {
                maxsum = tmaxsum;
                start = tstart;
            }
            if (tmaxsum < 0)
            {
                tmaxsum = 0;
                tstart = i + 1;
            }
        }
        return start;
    }

    int maxsubsum(vector<int> &nums)
    {
        int tmax(0), maxsum(numeric_limits<int>::min());
        for (auto num : nums)
        {
            tmax += num;
            maxsum = max(maxsum, tmax);
            if (tmax < 0)
                tmax = 0;
        }
        return maxsum;
    }
};


int main()
{
    Solution s;
    vector<int> gas = { 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66 };
    vector<int> cost = { 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
    cout << s.canCompleteCircuit(gas, cost) << endl;
    system("pause");
    return 0;
}