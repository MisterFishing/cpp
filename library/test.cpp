#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "MyStruct.h"
#include "MyClass.h"
using namespace std;

int main()
{
    struct Student1 a;
    Student2 b;

    SetName(&a,"ZhangSan");
    a.number = 1;
	a.score = 100;
 
    b.SetName("LiSi");
    b.number = 2;
    b.score = 90;

    cout << GetName(&a) << " " << a.number << " " << a.score << endl;
    cout << b.GetName() << " " << b.number << " " << b.score << endl;

    return 0;
}

