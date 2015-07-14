#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return{};
        int currentdna(0);
        int mask1((0x1 << 18) - 1);
        
        unordered_map<int, int> sequnces;
        vector<string> re;

        for (auto i = 0; i < 10; ++i)
        {
            currentdna <<= 2;
            currentdna |= getmask(s.at(i));
        }
        ++sequnces[currentdna];

        for (auto i = 10; i < s.size(); ++i)
        {
            currentdna &= mask1;
            currentdna <<= 2;
            currentdna |= getmask(s.at(i));
            ++sequnces[currentdna];
            if (sequnces[currentdna] == 2)
            {
                re.push_back(s.substr(i - 10 + 1, 10));
            }
        }
        return re;
    }
private:
    int getmask(char c)
    {
        if (c == 'A')
            return 0;
        if (c == 'C')
            return 1;
        if (c == 'G')
            return 2;
        return 3;
    }
};


int main()
{
    Solution s;
    string test("GAGAGAGAGAGA");
    auto re = s.findRepeatedDnaSequences(test);
    for (auto r : re)
        cout << r << endl;
    system("pause");
    return 0;
}