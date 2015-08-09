#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        if (cache.empty())
        {
            cache.push_back(ch);
            return;
        }
        auto i = find(cache.begin(), cache.end(), ch);
        if (i != cache.end())
            cache.erase(i);
        else
            cache.push_back(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        return cache.empty() ? '#' : cache.front();
    }

private:
    list<char> cache;
};


int main()
{
    Solution s;
    string test = "google";
    for (auto ch : test)
    {
        s.Insert(ch);
        cout << s.FirstAppearingOnce() << endl;
    }
    system("pause");
    return 0;
}