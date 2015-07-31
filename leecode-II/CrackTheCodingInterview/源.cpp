#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int ctci5_1_updatebits(int n, int m, int i, int j)
{
    int mask1 = ~0;
    mask1 << (j + 1);
    int mask2 = 1<<i;
    --mask2;
    int mask = mask1 | mask2;
    n &= mask;
    m <<= i;
    return n | m;
}

string ctci5_2_printbinary(double num)
{
    if (num >= 1 || num <= 0)
        return "ERROR";
    string re("0.");
    re.reserve(35);
    while (num > 0)
    {
        if (re.size() == 34)
            return "ERROR";
        double  r = num * 2;
        if (r >= 1)
        {
            re.push_back('1');
            num = r - 1;
        }
        else
        {
            re.push_back('0');
            num = r;
        }
    }
    return re;
}





int main()
{
    cout << ctci5_2_printbinary(0.75) << endl;
    system("pause");
    return 0;
}