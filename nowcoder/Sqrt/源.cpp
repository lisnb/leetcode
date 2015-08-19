#include <algorithm>
#include <iostream>

using namespace std;


double sqrt(const double number, int p)
{
    double precision(0.1);
    while (p-- > 1)
        precision *= 0.1;
    double lower, upper, guess;
    if (number < 1)
    {
        lower = number;
        upper = 1;
    }
    else
    {
        lower = 1;
        upper = number;
    }
    while ((upper - lower) > precision)
    {
        guess = (lower + upper) / 2;
        if (guess*guess > number)
            upper = guess;
        else
            lower = guess;
    }
    return (upper - lower) / 2;
}

int main()
{
    cout << 0.1*0.1*0.1*0.1*0.1*0.1 << endl;
    system("pause");
    return 0;
}