#include <iostream>
#include <string>

using namespace std;



void replacespace(string &s)
{
    typedef string::size_type stringsize;
    stringsize spacecnt(0);
    for (auto &c : s)
        spacecnt += c == ' ' ? 1 : 0;
    stringsize originalsize = s.size();
    stringsize finalsize = s.size() + spacecnt * 2;
    s.resize(finalsize);
    --finalsize;
    for (int i = originalsize - 1; i >= 0;--i)
    {
        if (s[i] == ' ')
        {
            s[finalsize--] = '0';
            s[finalsize--] = '2';
            s[finalsize--] = '%';
        }
        else
        {
            s[finalsize--] = s[i];
        }
    }
}




int main()
{
    string s1("1 2   3 4 5");
    s1.reserve(100);
    cout << s1 << endl;
    replacespace(s1);
    cout << s1 << endl;
    system("pause");
    return 0;
}