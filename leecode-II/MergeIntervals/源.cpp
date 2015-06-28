#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


typedef _leetcode_interval<int> Interval;








class Solution {
private:
    struct cmpinterval{
        bool operator()(const Interval &i1, const Interval &i2)
        {
            if (i1.start != i2.start)
                return i1.start < i2.start;
            return i1.end < i2.end;
        }
    };

public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmpinterval());
        vector<Interval> re;
        Interval first(intervals.front()), current;
        int lb(first.start), ub(first.end);
        for (int i = 1; i < intervals.size(); ++i)
        {
            current = intervals.at(i);
            if (current.start <= ub)
            {
                ub = max(current.end, ub);
            }
            else
            {
                re.push_back(Interval(lb, ub));
                lb = current.start;
                ub = current.end;
            }
        }
        if (re.empty()||re.back().end != ub)
            re.push_back(Interval(lb, ub));
        return re;
    }
private:
};


int main()
{

    Solution s;
    vector<Interval> test = { Interval(1, 4), Interval(4, 5), Interval(8, 10), Interval(15, 18) };
    auto re = s.merge(test);

    int a = int();
    cout << a << endl;
    system("pause");
    return 0;
}


