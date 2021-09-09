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
    static char school[10];

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

    static void set_school(char const * text)
    {
        strcpy(school, text);
        // score = 100; 
    }	
};

char student::school[10] = "UESTC";

int main()
{
    student::set_school("uestc");
    cout << student::school << endl;
    return 0;
}