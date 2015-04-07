#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        cache.clear();
        return numDecodings(s, 0);
    }

private:
    int numDecodings(string s, string::size_type b)
    {
        if (b < s.size() && s.at(b) == '0')
            return 0;// numDecodings(s, b + 1);

        if (b + 1 == s.size())
            return 1;
        if (b + 2 == s.size())
        {
            if (cache.find(b) == cache.end())
            {
                int t = atoi(s.substr(b, 2).c_str());
                if (t>26)
                    cache[b] = t % 10 == 0 ? 0 : 1;
                else 
                {
                    if (t == 10 || t == 20)
                        cache[b] = 1;
                    else
                        cache[b] = 2;
                }
            }
            return cache[b];

        }
        if (b >= s.size())
            return 0;

        if (cache.find(b) == cache.end())
        {
        
            int t = atoi(s.substr(b, 2).c_str());
            if (t > 26)
                cache[b] = t % 10 == 0 ? 0 : numDecodings(s, b + 1);
            else
            {
                if (t == 20 || t == 10)
                    cache[b] = numDecodings(s, b + 2);
                else
                    cache[b] = numDecodings(s, b + 2) + numDecodings(s, b + 1);
            }
        }
        return cache[b];
    }

    unordered_map<int, int> cache;
    
};


int main()
{
    Solution s;
    vector<string> test = {"230","0000","00001", "100001", "1001","0102", "201","101","0","01","100" ,"10", "112", "93715976311","9371597631128","9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253"
 };
    for (auto t : test)
    {
        cout << t << "\t" << s.numDecodings(t) << endl;
    }
    system("pause");

}