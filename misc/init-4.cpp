#include <iostream>
using namespace std;

class A
{
    public:
    A()
    {
        cout << "constructor" << endl;
        a = 0;
    }

    A(A const & x)
    {
        cout << "copy constructor" << endl;
        a = x.a;
    }

    int a;

};

int main()
{
    A a;
    A b(a);
    A c=a;
    A d=A();

    cout << d.a << endl;

    return 0;
}
