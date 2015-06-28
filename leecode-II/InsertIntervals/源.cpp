#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef _leetcode_interval<int> Interval;



class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
        vector<Interval> re;
        if (intervals.size() == 0)
        {
            re.push_back(newInterval);
            return re;
        }
        if (newInterval.end < intervals.front().start)
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if (newInterval.start > intervals.back().end)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int lb(0), ub(0), i(0);
        for (; i < intervals.size(); ++i)
        {
            if (intervals.at(i).end < newInterval.start)
            {
                re.push_back(intervals.at(i));
            }
            else
                break;
        }
        if (intervals.at(i).start<=newInterval.start&&intervals.at(i).end >= newInterval.end)
            return intervals;
        if (intervals.at(i).start > newInterval.end)
        {
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        }
        lb = min(intervals.at(i).start, newInterval.start);
        ub = max(intervals.at(i).end, newInterval.end);
        for (; i < intervals.size(); ++i)
        {
            if (intervals.at(i).start <= ub)
            {
                ub = max( intervals.at(i).end, newInterval.end );
            }
            else
                break;
        }
        re.push_back(Interval(lb, ub));
        if (i != intervals.size())
        {
            for (; i < intervals.size(); ++i)
                re.push_back(intervals.at(i));
        }
        
        return re;
    }
};


int main()
{

    Solution s;
    vector<Interval> test = { Interval(3, 5), Interval(12, 15) }; //, Interval(4, 6), Interval(8, 10), Interval(15, 18)

    auto newi = Interval(6, 6);
    auto re = s.insert(test, newi);

    int a = int();
    cout << a << endl;
    system("pause");
    return 0;
}
