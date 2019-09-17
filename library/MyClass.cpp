#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "MyClass.h"
using namespace std;

char* Student2::GetName()
{
    return name;
}

void Student2::SetName(char const *text)
{
    if(strlen(text)>10)
    {
        cout << "Name no more than 10!" << endl;
        exit(1);
    }
    strcpy(name,text);
}
