#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
        int loc = -1;
        int min = INT_MAX;
        int sum = 0;
        for (auto i = 0; i < gas.size(); ++i)
        {
            sum += (gas.at(i) - cost.at(i));
            if (sum < min)
            {
                min = sum;
                loc = i;
            }
        }
        return sum>0 ? loc + 1 : -1;
    }
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> remain;
        //vector<int> start;
        for (auto i = 0; i < gas.size(); ++i)
        {
            remain.push_back(gas.at(i) - gas.at(i));
        }
        int start = 0;
        while (start < remain.size())
        {
            while (remain.at(start) < 0)
                ++start;
            int tstart = start+1;
            int cost = remain.at(start);
            while (tstart != start)
            {
                if (tstart = remain.size())
                    tstart = 0;
                cost += remain.at(tstart);
                ++tstart;
                if (cost < 0)
                {
                    break;
                }
            }
            if (cost > 0)
                return start;
            while (remain.at(start) > 0)
                ++start;
        } 
        return -1;
    }

    int canCompleteCircuit(vector<int> &remain) {
        if (remain.size() == 1)
            return remain.at(0) > 0 ? 0 : -1;
        int min = INT_MAX;

    }
};


int main()
{
    Solution s;
    //vector<int> test = { -10, 4, 6, -4, -5, -10, 13, 1, 8 };*/
    vector<int> test = { -1,1 };
    cout << s.canCompleteCircuit(test) << endl;
    system("pause");
}