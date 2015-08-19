#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;



string abbreviation(string &ori)
{
    if (ori.size() < 3)
        return ori;
    else
    {
        stringstream ss;
        ss << ori[0] << ori.size() - 2 << ori.back();
        return ss.str();
    }
}

bool checkdup(vector<string> &dict, string word)
{
    string wordab(abbreviation(word));
    for (auto w : dict)
    {
        if (w != word && abbreviation(word) == wordab)
            return true;
    }
    return false;
}

int main()
{
    unordered_multimap<string, string> ummap;
}