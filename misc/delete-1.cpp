#include <iostream>
using namespace std;

const int num=1000000;

void func(int i)
{
    char *p;
    p=new char[num]();
    cout << i << endl;
    // delete []p;
}

int main()
{
    char x;
    for(int i=1; i<=4000; i++)
    {
        func(i);
        if( (i%500)==0 )
            cin >> x;
    }

    return 0;
}
