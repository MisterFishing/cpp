#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;
const int num=1000000;

void func(int i)
{
    char *p;
    p=new char[num];
    memset(p, 0, num);
    cout  << p << i << " MB"<< endl;
    delete []p;
}

int main()
{
    for(int i=1; i<=3000; i++){
        func(i);
		//Sleep(5);
    }

    system("pause");
    return 0;
}
