#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;
const int num=10000000;

void func(int i)
{
    char *p;
    p=new char[num];
    memset(p, 0, num);
    cout  << i << endl;
	// throw 404;
	// throw runtime_error("runtime error");
    delete []p;
}

int main()
{
	try
	{
		for(int i=1; i<=300; i++){
			func(i);
			//Sleep(5);
		}
	}
	catch(bad_alloc err)
	{
		cout << "Oh My God: " << err.what() << endl;
	}
	catch(int err)
	{
		cout << "Oh My God: " << err << endl;
	}
	catch(runtime_error err)
	{
		cout << "Oh My God: " << err.what() << endl;
	}
	
    system("pause");
    return 0;
}
