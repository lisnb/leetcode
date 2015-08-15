#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



char firstnonrepeating(const string &str)
{
    vector<pair<int, int>> counter(256, make_pair(0, -1));
    for (int i = 0; i < str.size(); ++i)
    {
        if (counter.at(str.at(i)).first == 0)
        {
            counter.at(str.at(i)).first = 1;
            counter.at(str.at(i)).second = i;
        }
        else
            ++counter.at(str.at(i)).first;
    }

    int singleindex(str.size());
    for (auto tchar : counter)
    {
        if (tchar.first == 1)
            singleindex = min(singleindex, tchar.second);
    }
    
    if (singleindex == -1)
        return '\0';
    else
        return str.at(singleindex);

}