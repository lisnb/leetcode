#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void vcout(vector<int> &cards)
{
    for (auto card : cards)
        cout << card << ' ';
    cout << endl;
}
default_random_engine e;
void shuffle(vector<int> cards)
{
    if (cards.size()<=1)
        return;
    
    //e.seed(2);
    for (int i = 1; i < cards.size(); ++i)
    {
        unsigned int index = e();
        index %= (i + 1);
        cout << index << "   ";
        swap(cards[i], cards[index]);
        //vcout(cards);
    }
    vcout(cards);
}



int main()
{
    vector<int> cards(10, 0);
    for (int i = 0; i < 10; ++i)
        cards[i] = i;
    for (int i = 0; i < 10; ++i)
    {
        e.seed(i); 
        shuffle(cards);
        
    }
        
    system("pause");
    return 0;
}