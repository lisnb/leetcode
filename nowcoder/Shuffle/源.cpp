#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

using namespace std;



void shuffle(vector<int> &nums)
{
    bool up = true;
    for (int i = 0; i+1 < nums.size(); ++i)
    {
        if (up)
        {
            if (nums[i]>nums[i+1])
                swap(nums[i], nums[i + 1]);
        }
        else
        {
            if (nums[i] < nums[i + 1])
                swap(nums[i], nums[i + 1]);
        }
        up = !up;
    }
}


int main()
{
    vector<int> test;// = { 1, 2, 3, 4, 5, 6, 7 };
    default_random_engine e;
    for (int i = 0; i < 100; ++i)
        test.push_back(e()%100);
    shuffle(test);
    for (auto i : test)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;

}