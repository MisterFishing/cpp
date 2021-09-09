#include <iostream>
using namespace std;

int func(char * x)
{
    cout << x << endl;
    return 0;
}

int main()
{
    func("hello");
    return 0;
}
