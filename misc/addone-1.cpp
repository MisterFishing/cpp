#include <iostream>

using namespace std;

char addone(char x)
{
    cout << "char: ";
    return (x+1);
}

int addone(int x)
{
    cout << "int: ";
    return (x+1);
}

float addone(float x)
{
    cout << "float: ";
    return (x+1);
}

double addone(double x)
{
    cout << "double: ";
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