#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "MyStruct.h"
using namespace std;

char* GetName(struct Student1 * x)
{
    return x->name;
}

void SetName(struct Student1 * x, char const* text)
{
    if(strlen(text)>10)
    {
        cout << "Name no more than 10!" << endl;
        exit(1);
    }
    strcpy(x->name,text);
}
