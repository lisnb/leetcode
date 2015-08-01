#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <numeric>
#include <functional>


using namespace std;


int ctci5_1_updatebits(int n, int m, int i, int j)
{
    int mask1 = ~0;
    mask1 << (j + 1);
    int mask2 = 1<<i;
    --mask2;
    int mask = mask1 | mask2;
    n &= mask;
    m <<= i;
    return n | m;
}

string ctci5_2_printbinary(double num)
{
    if (num >= 1 || num <= 0)
        return "ERROR";
    string re("0.");
    re.reserve(35);
    while (num > 0)
    {
        if (re.size() == 34)
            return "ERROR";
        double  r = num * 2;
        if (r >= 1)
        {
            re.push_back('1');
            num = r - 1;
        }
        else
        {
            re.push_back('0');
            num = r;
        }
    }
    return re;
}



string longestWord(vector<string> &strs)
{
    unordered_map<string, bool> cache;
    for (auto str : strs)
        cache.insert(make_pair(str, true));
    sort(strs.rbegin(), strs.rend());
    for (auto str : strs)
    {
        if (_canbuild(str, cache, true))
            return str;
    }
    return "";
}

bool _canbuild(string str, unordered_map<string, bool> &cache, bool isorig)
{
    if (cache.find(str) != cache.end() && !isorig)
        return cache.at(str);
    for (int i = 1; i < str.size(); ++i)
    {
        string left = str.substr(0, i);
        if (cache.find(left) != cache.end() && cache.at(left))
        {
            string right = str.substr(i);
            if (_canbuild(right, cache, false))
                return true;
        }
    }
    cache[str] = false;
    return false;
}



priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

void addnewnumber(int randomnumber)
{
    if (maxheap.size() == minheap.size())
    {
        if (!minheap.empty() && randomnumber > minheap.top())
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(randomnumber);
        }
        else
            maxheap.push(randomnumber);
    }
    else
    {
        if (randomnumber < maxheap.top())
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(randomnumber);
        }
        else
            minheap.push(randomnumber);
    }
}

double getmedian()
{
    if (maxheap.empty())
        return 0;
    if (maxheap.size() == minheap.size())
        return (double)(minheap.top() + maxheap.top()) / 2;
    else
        return maxheap.top();
}



int main()
{
    cout << ctci5_2_printbinary(0.75) << endl;
    system("pause");
    return 0;
}