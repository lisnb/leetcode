#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;



class Solution{

public:
    template<typename _Iter>
    int lis(_Iter _First, _Iter _Last)
    {
        if (_First == _Last)
            return 0;
        vector<int> lises(_Last-_First, 1);
        for (_Iter cur = _First+1; cur != _Last; ++cur)
        {
            for (_Iter temp = _First; temp != cur; ++temp)
            {
                if (*cur > *temp)
                    lises.at(cur - _First) = max(lises.at(cur - _First), lises.at(temp - _First) + 1);
            }
        }
        return *max_element(lises.begin(), lises.end());
    }


    template<typename _iter>
    int lis2(_iter _first, _iter _last)
    {
        if (_first == _last)
            return 0;
        size_t size = _last - _first;
        vector<int> lises(size, 1);
        vector<int> maxv(size+1);
        maxv[0] = *min_element(_first, _last) - 1;
        maxv[1] = *_first;
        int maxlis = 1;
        for (int i = 1; i < size; ++i)
        {
            int j = lises.at(i - 1);
            for (; j >= 1; --j)
            {
                if (*(_first + i) > maxv.at(j))
                {
                    lises.at(i) = j + 1;
                    break;
                }
            }

            if (lises.at(i) > maxlis)
            {
                maxlis = lises.at(i);
                maxv.at(lises.at(i)) = *(_first + i);
            }
            else if (maxv.at(j) < *(_first + i) && maxv.at(j + 1) > *(_first + i))
                maxv.at(j + 1) = *(_first + i);

        }
        return maxlis;
    }

    
    int lis3(vector<int> &nums)
    {
        vector<int> lises(nums.size(), 1), maxv(nums.size() + 1, 0);
        maxv.at(1) = nums.at(0);
        maxv.at(0) = *min_element(nums.begin(), nums.end()) - 1;
        int maxlis = 1;
        for (auto i = 1; i < nums.size(); ++i)
        {
            int j;/* = lises.at(i - 1);
            for (j = lises.at(i - 1); j >= 1; --j)
            {
                if (nums.at(i) > maxv.at(j))
                {
                    lises.at(i) = j + 1;
                    break;
                }
            }
            */
            for (j = maxlis; j >= 1; --j)
            {
                if (nums.at(i) > maxv.at(j))
                {
                    lises.at(i) = j + 1;
                    break;
                }
            }

            if (lises.at(i) > maxlis)
            {
                maxlis = lises.at(i);
                maxv.at(lises.at(i)) = nums.at(i);
            }
            else if (maxv.at(j) < nums.at(i) && maxv.at(j + 1) > nums.at(i))
                maxv.at(j + 1) = nums.at(i);
        }
        return maxlis;
    }
};

int main()
{
    Solution s;
    vector<int> seq1 = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    //string seq2 = "567128";
    cout << s.lis(seq1.begin(), seq1.end()) << endl;
    cout << s.lis3(seq1) << endl;
    //cout << s.lis(seq2.begin(), seq2.end()) << endl;
    system("pause");
    return 0;
}