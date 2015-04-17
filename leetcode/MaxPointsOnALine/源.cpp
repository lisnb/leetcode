#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;



/**
* Definition for a point.
*/


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    
    long long pointhasher(const Point &p)
    {
        long long px = long long(p.x);
        return hash<long long>()((px<<32) | p.y);
    }
    bool eqpoint(const Point &p1, const Point &p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }
public:

    int maxPoints(vector<Point> &points)
    {
        if (points.size() < 3)
            return points.size();

        unordered_map<double, int> lines;
        size_t maxp = 0;
        for (auto i = 0; i < points.size(); ++i)
        {
            lines.clear();
            size_t same = 1;
            for (auto j = i + 1; j < points.size(); ++j)
            {
                if (points.at(i).x == points.at(j).x && points.at(i).y == points.at(j).y)
                    ++same;
                double dy = points.at(j).y - points.at(i).y;
                double dx = points.at(j).x - points.at(i).x;
                double line(0);
                if (dx == 0)
                    line = numeric_limits<double>::max();
                else
                    line = dy / dx;
                ++lines[line];
            }
            if (lines.empty())
            {
                maxp = max(maxp, same);
                continue;
            }
            for (auto i : lines)
                maxp = max(maxp, i.second + same);
        }
        return maxp;
    }

    typedef unordered_map<Point, unordered_set<Point, decltype(pointhasher)*, decltype(eqpoint)*>, decltype(pointhasher)*, decltype(eqpoint)*> pointmap;
    int maxPointsTLE(vector<Point> &points) {
        if (points.size() <= 2)
            return points.size();

        unordered_map<long long, unordered_set<long long>> cache;

        int maxpn = -1;
        for (auto i = 0; i < points.size(); ++i)
        {
            for (auto j = i + 1; j < points.size(); ++j)
            {
                auto hashi = pointhasher(points.at(i));
                auto hashj = pointhasher(points.at(j));
                if (cache[hashi].find(hashj) != cache[hashi].end())
                    continue;
                int cnt = 2;
                for (auto k = j + 1; k < points.size(); ++k)
                {
                    auto hashk = pointhasher(points.at(k));
                    if (cache[hashi].find(hashk) != cache[hashi].end() || cache[hashj].find(hashk) != cache[hashj].end())
                        continue;
                    if (isonaline(points.at(i), points.at(j), points.at(k)))
                    {
                        ++cnt;
                        cache[hashi].insert(hashk);
                        cache[hashj].insert(hashk);
                    }
                }
                maxpn = max(maxpn, cnt);
            }
        }
        return maxpn;
    }

private:
    bool isonaline(Point &p1, Point &p2, Point &p3)
    {
        return (p3.y - p1.y)*(p2.x - p1.x) == (p2.y - p1.y)*(p3.x - p1.x);
    }
};


int main()
{
    Solution s;
    cout << sizeof(int) << sizeof(long long) << endl;
    vector<Point> test = {
        Point(0, 2),
        Point(0, 4),
        Point(0, 6),
        Point(0, 8),
        Point(1, 2),
        Point(2, 2),
        Point(5, 6)
    };
    cout << s.maxPoints(test) << endl;
    system("pause");
}