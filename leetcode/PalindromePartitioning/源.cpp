#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;



class Solution {
public:
    vector<vector<string>> partition(string s) {
        cache.clear();
        return partitionit(s, 0);
    }
private:
    vector<vector<string>> partitionit(string s, string::size_type b)
    {
        if (cache.find(b) != cache.end())
            return cache[b];
        vector<vector<string>> re;
        if (b == s.size())
            return re;
        for (auto i = b; i < s.size(); ++i)
        {
            if (ispalindrome(s, b, i))
            {
                vector<vector<string>> tre = partitionit(s, i + 1);
                if (tre.empty())
                {
                    re.push_back({ s.substr(b, i - b + 1) });
                }
                else
                {
                    for (auto trei : tre)
                    {
                        trei.insert(trei.begin(), s.substr(b, i - b + 1));
                        re.push_back(trei);
                    }
                }
            }
        }
        cache[b] = re;
        return re;
    }
    map<int, vector<vector<string>>> cache;
    bool ispalindrome(const string &s, string::size_type b, string::size_type e)
    {
        if (b == e)
            return true;
        while (b < e && b < s.size() && e >= 0)
        {
            if (s.at(e) != s.at(b))
                return false;
            ++b;
            --e;
        }
        return true;
    }
};


int main()
{
    Solution s;
    vector<string> test = {"aab","aa", "abcba", "a", "abcb", "aaa", "abba" };
    for (auto t : test)
    {
        //cout << t << "\t" << s.ispalindrome(t,0,t.size()-1) << endl;
        cout << t << endl;
        for (auto i : s.partition(t))
        {
            cout << "[ ";
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "]\n";
        }
    }

    system("pause");
}