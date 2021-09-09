#include <iostream>
#include <string.h>
using namespace std;

const int num=1000000;

class student
{
    public:

    char name[10];
    int number;
    int score;
    char * resume;
    
    student()
    {
        resume=new char[num]();
    }

    ~student()
    {
        delete[] resume;
    }

    student(student & s)
    {
        strcpy(name,s.name);
        number=s.number;
        score=s.score;
        resume=new char[num]();
        strcpy(resume,s.resume);
    }

};

void func(int i)
{
    student zs;
    student ls(zs);
    cout  << i << endl;
}

int main()
{
    char x;
    for(int i=1; i<=4000; i++)
    {
        func(i);
        if( (i%500)==0 )
            cin >> x;
    }

    return 0;
}
