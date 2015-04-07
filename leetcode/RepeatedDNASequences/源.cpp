#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given: 
s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
Return:
["AAAAACCCCC", "CCCCCAAAAA"].

*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> recs;
        vector<string> re;
        if (s.size() < 11)
            return re;
        int mask = 0;
        int v = 1;
        v <<= 27;
        v -= 1;
        for (auto i = 0; i < 10; ++i)
        {
            mask <<= 3;
            mask |= (s[i] & 7);
        }
        recs[mask]++;
        for (auto i = 1; i < s.size() - 9;++i)
        {
            mask &=v;
            mask <<= 3;
            mask |= (s[i+9] & 7);
            
            if (recs[mask]++ == 1)
            {
                re.push_back(s.substr(i, 10));
            }
        }
        return re;
    }
    vector<string> MLEfindRepeatedDnaSequences(string s) {
        vector<string> re;
        if (s.size() < 11)
            return re;
        unordered_map<string, int> records;

        auto b = 0;
        string t("");
        while (b + 9 < s.size())
        {
            t = s.substr(b, 10);
            if (records.find(t) != records.end())
                ++records[t];
            else
                records[t] = 1;
            ++b;
        }
        for (auto r : records)
        {
            if (r.second > 1)
                re.push_back(r.first);
        }
        return re;

    }
};


int main()
{
    Solution s;
    vector<string> test = { "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT","AAAAAAAAA","AAAAAAAAAA","AAAAAAAAAAA" };
    for (auto t : test)
    {
        cout << "[ " << t << " ]" << endl;
        for (auto tt : s.findRepeatedDnaSequences(t))
        {
            cout << tt << endl;
        }
        cout << endl;
    }
    system("pause");
}