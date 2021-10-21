#include <iostream>

using namespace std;

template <class T>
T addone(T x)
{
    cout << "T: ";
    return (x+1);
}

int main()
{
    char x1='a';
    int x2=1;
    float x3=1.1;
    double x4=1.11;
	
    cout << addone(x1) << endl;
    cout << addone(x2) << endl;
    cout << addone(x3) << endl;
    cout << addone(x4) << endl;

    return 0;
}