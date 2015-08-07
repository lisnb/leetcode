#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int equalpartition(vector<int> &nums)
{
    vector<int> lefts(nums.size(), 0);
    int sum(nums.at(0));
    for (auto i = 1; i < nums.size(); ++i)
    {
        sum += nums.at(i);
        lefts.at(i) = nums.at(i - 1) + lefts.at(i - 1);
    }
    for (auto i = 0; i < nums.size(); ++i)
    {
        int right = sum - nums.at(i) - lefts.at(i);
        int left = lefts.at(i);
        if (left == right)
            return i;
    }
    return -1;
}


int main()
{
    vector<int> test = { 1, 2, 3, 4, 5, 6, 10, 5 };
    cout << equalpartition(test) << endl;
    system("pause");
    return 0;
}