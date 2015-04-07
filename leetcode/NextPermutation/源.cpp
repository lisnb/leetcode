#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() < 2)
            return;
        int i(-1);
        for (int j = num.size() - 1; j >= 0; --j)
        {
            if (j - 1 >= 0 && num.at(j) > num.at(j - 1))
            {
                i = j;
                break;
            }
        }
        if (i == -1)
        {
            sort(num.begin(), num.end());
            return;
        }
        int h(-1);
        for (int k = num.size() - 1; k >= 0; --k)
        {
            if (num.at(k) > num.at(i - 1))
            {
                h = k;
                break;
            }
        }
        swap(num.at(i-1), num.at(h));
        reverse(num.begin() + i, num.end());
    }
};


int main()
{
    Solution s;
    vector<vector<int>> test = {
        {2,1,3},
        { 1, 2, 3 },
        { 3, 2, 1 },
        { 5, 3, 2, 4, 1 },
        {1,3,2}
    };
    
    for (auto t : test)
    {
        for (auto tt : t)
        {
            cout << tt << " ";
        }
        cout << " => ";
        s.nextPermutation(t);
        for (auto tt : t)
        {
            cout << tt << " ";
        }
        cout << endl;

    }


    system("pause");
}