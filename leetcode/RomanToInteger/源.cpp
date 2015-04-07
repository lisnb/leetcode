#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        if (s.empty())
            return 0;
        map<char, int> dict = {
            { 'M', 1000 },
            { 'D', 500 },
            { 'C', 100 },
            { 'L', 50 },
            { 'X', 10 },
            { 'V', 5 },
            { 'I', 1 }
        };
        //if (s.size() == 1)
            //return dict.at(s.at(0));
        //������ֱ���һλ��IVX�Ƿ������Ե�s[i]<s[i+1]ʱ��s[i+1]һ������s[i+2]

        int re = 0;
        int i = 0;
        int t;
        while (i < s.size())
        {
            t = dict.at(s.at(i));
            if (i + 1 == s.size())
            {
                re += t;
                return re;
            }
            if (t < dict.at(s.at(i + 1)))
                re -= t;
            else
                re += t;
            i++;
        }
        return re;
    }
};


int main()
{
    Solution s;
    vector<string> test = { "MMMCMXCIX", "CMXCIX", "MMDXXXVII", "IIIV"};
    for (auto t : test)
    {
        cout << t << "\t" << s.romanToInt(t) << endl;
    }
    system("pause");
}