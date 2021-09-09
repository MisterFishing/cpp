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
        cout << "constructor 1" << endl;
        
        strcpy(name,"none");
        number=0;
        score=0;      
    }

    student(char const * text)
    {
        cout << "constructor 2" << endl;
        
        if(strlen(text)>=10) 
        {
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }

        strcpy(name,text);     
    }   

    student(char const * text, int n, int s)
    {
        cout << "constructor 3" << endl;
        
        if(strlen(text)>=10) 
        {
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }

        strcpy(name,text);     
        number=n;
        score=s;        
    }

    student(const student & s)
    {
        cout << "constractor copy" << endl;

        strcpy(name,s.name);
        number=s.number;
        score=s.score;
    }

    char* get_name() 
	{
        return name;
    }

    void set_name(char const *text) 
	{
        if(strlen(text)>10) 
		{
            cout << "Your input seems have some problem." << endl;
            exit(0);
        }
		
        strcpy(name,text);
    }
	
};

int main()
{
    student zs;
    cout << zs.get_name() << " " << zs.number << " " << zs.score  << endl;
    return 0;
}

