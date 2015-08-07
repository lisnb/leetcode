#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> ugly = {1};
        int ti(1);
        int t2(0), t3(0), t5(0);
        while (ti < index)
        {
            ugly.push_back(min({ ugly.at(t2) * 2, ugly.at(t3) * 3, ugly.at(t5) * 5 }));
            ++ti;
            while (ugly.at(t2) * 2 <= ugly.back())
                ++t2;
            while (ugly.at(t3) * 3 <= ugly.back())
                ++t3;
            while (ugly.at(t5) * 5 <= ugly.back())
                ++t5;
        }
        for (auto i = 0; i < ugly.size(); ++i)
            cout << i << " " << ugly.at(i) << endl;
        return ugly.back();
    }
};


int main()
{
    Solution s;
    cout << s.GetUglyNumber_Solution(100) << endl;
    system("pause");
    return 0;
}