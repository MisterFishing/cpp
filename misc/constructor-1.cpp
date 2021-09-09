#include <iostream>
#include <string.h>
using namespace std;

class student
{
    public:

    char name[10];
    int number;
    int score;

    student(char const * text)
    {
        strcpy(name,text);     
    }

    student(char const * text, int n, int s)
    {
        strcpy(name,text);     
        number=n;
        score=s;        
    }

    void display()
    {
        cout << name << " " << number << " " << score  << endl;
    }
	
};

int main()
{
    student zs;
    zs.display();
    return 0;
}
