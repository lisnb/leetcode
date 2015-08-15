#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;


class Company
{
public:
    virtual void SayHello() const = 0;
};

class Qihoo : public Company
{
public :
    Qihoo(const char *name) :name_(strdup(name)){}
    ~Qihoo(){ free(name_); }
    virtual void SayHello()const{
        printf("Hello, we are from %s\n", name_);
    }
private:
    char *name_;
};




int main()
{
    Company *qihoo = new Qihoo("Qihoo");
    //Qihoo qihoo("Qihoo");
    cout << sizeof(qihoo) << endl;
    system("pause");
    return 0;
}