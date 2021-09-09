#include <iostream>
#include <string.h>
using namespace std;

class student
{
    private:
    char name[10];

    public:
    int const number;
    int score;

    student():number(0)
    {
        strcpy(name,"none");
        score=0;      
    }

    student(char const * text):number(0)
    {
        strcpy(name,text);     
        score=0;   
    }

    student(char const * text, int n, int s):number(n)
    {
        strcpy(name,text);     
        score=s;        
    }

    student(student const & s):number(s.number)
    {
        strcpy(name,s.name);
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

    void display() const
    {
        cout << name << " " << number << " " << score  << endl;
    }
	
};

int main()
{
    student zs("zhangsan");
    zs.display();

    student const ls("lisi",2,80);
    ls.display();

    return 0;
}