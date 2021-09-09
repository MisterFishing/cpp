#include <iostream>
using namespace std;

int func(int & x)
{
    return 0;
}

int main()
{
    func(1);
    return 0;
}

