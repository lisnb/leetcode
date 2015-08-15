#include <iostream>
using namespace std;



class StashOnly
{
protected:
    ~StashOnly(){}
    StashOnly(){}
public:
    static StashOnly* create()
    {
        return new StashOnly();
    }

    void destroy()
    {
        delete this;
    }
};


class StackOnly
{
private:
    void* operator new(size_t t){}
    void operator delete(void*){}
public:
    StackOnly(){}
    ~StackOnly(){}

};

int main()
{
    auto t = StashOnly::create();
    auto c = new StackOnly();
    system("pause");
    return 0;
}