#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SingletonStatic
{
private:
    static SingletonStatic *instance;
    SingletonStatic(){}
public:
    static const SingletonStatic *getInstance()
    {
        return instance;
    }
    int label;
};


SingletonStatic * SingletonStatic::instance = new SingletonStatic();

class Singleton
{
private:
    static Singleton *instance;
    Singleton(){}
public:
    static Singleton *getInstance();
};

Singleton *Singleton::getInstance()
{
    if (Singleton::instance == nullptr)
    {
        //lock();
        if (Singleton::instance == nullptr)
            instance == new Singleton;
        //unlock();
    }
    return instance;
}

class SingletonInside
{
private:
    SingletonInside(){}
public:
    static SingletonInside *getInstance()
    {
        //lock() //not necessary in C++0x
        static SingletonInside instance;
        //unlock() 
        return &instance;
    }
};



int main()
{
    auto i = SingletonStatic::getInstance();
    cout << i->label << endl;
    system("pause");
    return 0;
}

