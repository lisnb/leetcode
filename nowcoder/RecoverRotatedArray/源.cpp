#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;



template<typename T>
int findpivot(vector<T> &items)
{
    int b(0), e(items.size() - 1);
    while (b < e)
    {
        if (items.at(b) < items.at(e))
            return b;
        if (items.at(b) == items.at(e))
            ++b;
        if (b + 1 == e)
            return items.at(b) > items.at(e) ? e : b;
        int mid = b + (e - b) / 2;
        if (items.at(mid) < items.at(mid - 1))
            return mid;
        if (items.at(mid) > items.at(e))
            b = mid + 1;
        else if (items.at(mid) == items.at(e))
            --e;
        else
            e = mid - 1;
    }
    return b;
}

template<typename T>
int findpivot2(vector<T> &items)
{
    int i(0);
    while (i + 1 < items.size())
    {
        if (items.at(i) > items.at(i + 1))
            return i + 1;
        ++i;
    }
    return 0;
}

template<typename T>
void reverse(vector<T> &items, int b, int e)
{
    while (b < e)
        swap(items.at(b++), items.at(e--));
}


template<typename T>
void recover(vector<T> &items)
{
    if (items.size() <= 1)
        return;
    int pivot = findpivot2(items);
    if (pivot == 0)
        return;
    reverse(items, 0, pivot - 1);
    reverse(items, pivot, items.size() - 1);
    reverse(items, 0, items.size() - 1);
}


int main()
{
    vector<int> test = { 1, 1, 3, 3, 3, 3, 4, 5, 6, 7 };
    recover(test);
    for (auto t : test)
        cout << t << " ";
    cout << endl;
    system("pause");
    return 0;
}