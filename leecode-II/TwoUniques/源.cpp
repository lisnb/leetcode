#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        if (data.size() < 2)
            return;
        int xor(0);
        for (auto num : data)
            xor ^= num;
        //cout << xor << endl;
        int mask = findfirst1mask(xor);
        //cout << mask << endl;
        *num1 = 0;
        *num2 = 0;
        for (auto num : data)
        {
            if ((num&mask) == 0) 
                *num1 ^= num;
            else
                *num2 ^= num;
        }
    }

private:
    int findfirst1mask(int i)
    {
        int mask(1);
        while ((mask&i) == 0)
            mask <<= 1;
        return mask;
    }
};



int main()
{
    Solution s;
    vector<int> test = { 2, 4};
    int num1, num2;
    s.FindNumsAppearOnce(test, &num1, &num2);
    cout << num1 << " " << num2 << endl;
    system("pause");
    return 0;
}