#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >re;
        int b = 0;
        while (b+2 < num.size()) // at least 3 number
        {
            twosum(num, 20 - num.at(b), b + 1, re, num.at(b));
            while (b < num.size() - 2 && num.at(b) == num.at(b + 1))
                ++b;
            ++b;
        }
        return re;
    }

    void twosum(vector<int> &num, int target, int b, vector<vector<int> > &re, int cur)
    {
        int e = num.size() - 1;
        while (b < e)
        {
            if (num.at(b) + num.at(e) > target){
                --e;
            }
            else if (num.at(b) + num.at(e) < target){
                ++b;
            }
            else{
                vector<int> t = { cur, num.at(b), num.at(e) };
                re.push_back(t);
                while (b < e && num.at(b) == num.at(b + 1) && b<num.size())
                    ++b;
                while (b < e &&num.at(e) == num.at(e - 1) && e>b)
                    --e;
                ++b;
                --e;
            }
        }
    }

    vector<vector<int>> twoSum(vector<int> &num, int target){
        sort(num.begin(), num.end());
        for (auto i : num)
            cout << i << " ";
        cout << endl;
        auto b = num.cbegin();
        auto e = num.cend()-1;
        vector<vector<int>> re;
        while (b < e)
        {
            if (*b + *e > target){
                --e;
            }
            else if (*b + *e < target){
                ++b;
            }
            else
            {
                vector<int> t = { *b, *e };
                re.push_back(t);
                while (b < e && *b == *(b + 1))
                {
                    ++b;
                }
                while (e > b && *e == *(e-1))
                {
                    --e;
                }
                ++b;
                --e;
            }
        }
        return re;
    }
};



int main()
{
    Solution s;
    //vector<int> num = { 5, 6, 1, 4, 7, 9, 8 ,1,1,9,9,0,10,4,6,6,5,5};
    vector<int> num = { };
    //auto re = s.twoSum(num, 10);
    auto re = s.threeSum(num);
    for (auto i1 : re)
    {
        for (auto i2 : i1)
        {
            cout << i2 << "\t";
        }
        cout << endl;
    }
    system("pause");

}
