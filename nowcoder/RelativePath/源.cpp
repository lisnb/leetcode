#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void strsplit(string &str, vector<string> &tokens)
{
    stringstream ss(str);
    string item("");
    while (getline(ss, item, '/'))
    {
        if (!item.empty())
            tokens.push_back(item);
    }
}

string relativePath(string &a, string &b)
{
    vector<string> tokensa, tokensb;
    strsplit(a, tokensa);
    strsplit(b, tokensb);
    int shortestpath = min(tokensa.size(), tokensb.size());
    int commonprefixindex(0);
    while (commonprefixindex<shortestpath && tokensa.at(commonprefixindex) == tokensb.at(commonprefixindex))
        ++commonprefixindex;
    stringstream ss;
    for (auto i = commonprefixindex+1; i < tokensa.size(); ++i)
        ss << "../";
    for (auto i = commonprefixindex; i < tokensb.size(); ++i)
        ss << tokensb.at(i) << '/';
    string rp(ss.str());
    rp.pop_back();
    return rp;
}




int main()
{
    string pa("/qihoo/app/a/b/c/d/new.c"), pb("/qihoo");
    cout << relativePath(pa, pb) << endl;
    system("pause");
    return 0;
}