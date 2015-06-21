#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int w1(abs(C - A)), h1(abs(D - B)), w2(abs(G - E)), h2(abs(H - F));
        int wmax(max({ A, E, C, G })), wmin(min({ A, E, C, G })), hmax(max({ D, B, H, F })), hmin(min({ D, B, H, F }));
        int w(wmax - wmin), h(hmax - hmin);
        if (w1 + w2 < w || h1 + h2 < h)
            return 0;
        else
            return ((w1 + w2) - w)*((h1 + h2) - h);
    }
};


int main()
{
    Solution s;
    cout << s.computeArea(-3, 0, 3, 4, -3, -1, 9, 4) << endl;
    system("pause");
    return 0;
}