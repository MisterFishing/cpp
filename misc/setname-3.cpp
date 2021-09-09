#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class student
{
    private:
    char name[10];
	
    public:
    int number;
    int score;

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
        cout << name << " " << number << " " << score << endl;
    }

};

int main()
{
    student zs;

    zs.set_name("zhangsan");
    zs.number = 1;
    zs.score = 90;
    zs.display();

    return 0;
}
