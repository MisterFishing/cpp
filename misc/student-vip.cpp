#include <iostream>
#include <string.h>
using namespace std;

class student
{
    private:

    char name[10];
    int number;
    int score;
    static student * vip;

    student(char const * name, int number, int score)
    {
        if(strlen(name)>=10) 
        {
            cout << "length of " << name << " >= 10 " << endl;
            exit(0);
        }

        strcpy(this->name,name);     
        this->number=number;
        this->score=score;
    }

    public:

    void display()
    {
        cout << name << " " << number << " " << score << endl;
    }
    
    static student * new_student(char const * name, int number, int score)
    {
        if(vip==NULL) 
            vip=new student(name, number, score);
        else
            cout << "sorry, only one vip" << endl;
        return vip;   
    }
    
};

student * student::vip = NULL;

int main()
{
    student *zs = student::new_student("zhangsan", 1, 90);
    zs->display();

    student *ls = student::new_student("lisi", 2, 80);
    ls->display();
    
    student *ww = student::new_student("wangwu ", 3, 70);
    ww->display();
    
    return 0;
}