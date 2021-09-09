#include <iostream>
#include <string.h>
using namespace std;

class student
{
    private:
    char name[10];

    public:
    int number;
    int score;

    student()
    {
        strcpy(name,"none");
        number=0;
        score=0;      
    }

    student(char const * text)
    {
        strcpy(name,text);     
        number=0;
        score=0;   
    }

    student(char const * text, int n, int s)
    {
        strcpy(name,text);     
        number=n;
        score=s;        
    }

    student(student & s)
    {
        strcpy(name,s.name);
        number=s.number;
        score=s.score;
    }
    
    ~student()
    {        
    }

    void set_name(char const * text) 
    {
        if(strlen(text)>=10) 
        {
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }
        strcpy(name,text);
    }

    void display()
    {
        cout << name << " " << number << " " << score  << endl;
    }
	
};

int main()
{
    student zs=student();
    zs.display();

    student ls=student("lisi");
    ls.display();

    student ww=student("wangwu,3,80");
    ww.display();
    
    return 0;
}
