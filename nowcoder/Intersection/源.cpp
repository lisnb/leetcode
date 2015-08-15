#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


vector<int> insersection(vector<int> &A, vector<int> &B)
{
    unordered_set<int> bset(B.begin(), B.end());
    vector<int> re;
    for (auto a : A)
    {
        if (bset.find(a) != bset.end())
            re.push_back(a);
    }
    return re;

    //char const a[130];
    //a[5] = 6;

    int b = 9;
    int c = 0;
    int * const  a = &b;

}


int main()
{
    cout << (-7 % 3) << endl;
    system("pause");
    return 0;
}
