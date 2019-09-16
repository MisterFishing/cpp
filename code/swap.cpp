#include <iostream>
using namespace std;

void swap(int x, int y)
{
    int tmp;
    tmp=x;
    x=y;
    y=tmp;
}

int main()
{
    int a,b;

    cout << "input a b: ";
    cin >> a >> b;
	cout << "----------" << endl;
    cout << "a=" << a << " " << "b=" << b <<endl;
    swap(a, b);
	cout << "----------" << endl;
    cout << "a=" << a << " " << "b=" << b <<endl;

    return 0;
}

