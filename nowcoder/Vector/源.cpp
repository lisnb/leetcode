#include <vector>
#include <iostream>

using namespace std;


class Item
{
public:
    Item(){
        
        ++Item::index;
        tindex = Item::index;
        cout << tindex << endl;
    }
    Item(const Item &item)
    {
        tindex = item.tindex;
        cout << "copy: " <<tindex<< endl;
    }
    int tindex;
    static int index;
};


int Item::index = 0;

int main()
{
    vector<Item> items(8);
    cout << "capacity: " << items.capacity() << endl;
    items.push_back(Item());
    cout << "capacity: " << items.capacity() << endl;
    system("pause");
    return 0;

}