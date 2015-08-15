#include <algorithm>
#include <random>
#include <vector>
#include <iostream>
#include <exception>
#include <queue>
#include <cassert>

using namespace std;



int partition(vector<int> &nums, int b, int e)
{
    if (b >= e)
        return b;
    int p1(b), p2(b + 1);
    while (p2 <= e)
    {
        if (nums.at(p2) < nums.at(b))
            swap(nums.at(++p1), nums.at(p2));
        ++p2;
    }
    swap(nums.at(b), nums.at(p1));
    return p1;
}

void quicksort(vector<int> &nums, int b, int e)
{
    if (b >= e)
        return;
    int pivot = partition(nums, b, e);
    quicksort(nums, b, pivot - 1);
    quicksort(nums, pivot + 1, e);
}

int main()
{
    queue<int> q;
    try
    {
        //q.pop();
        cout << q.front() << endl;
    }
    catch (range_error ex)
    {
        cout << ex.what() << endl;
    }
    catch (runtime_error ex)
    {
        cout << ex.what() << endl;
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }
    
    vector<int> nums;
    default_random_engine e(4);
    for (auto i = 0; i < 20; ++i)
        nums.push_back(e()%30);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    quicksort(nums, 0, nums.size() - 1);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    system("pause");
    return 0;
}