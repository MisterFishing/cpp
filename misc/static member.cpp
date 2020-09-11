#include <iostream>
using namespace std;

class Student {
    int id;
    int score;

public:
    static int room;

    Student(int newid, int newscore):id(newid){
        score=newscore;
    }

    int getid() const{
        return id;
    }

    int getscore() const{
         return score;
    }

    void setscore(int newscore){
        score=newscore;
    }
};

int Student::room=0;

int main()
{
	Student::room=202;
    Student stu1(1,90);
    cout << "id:" << stu1.getid() << endl;
    cout << "score:" << stu1.getscore() << endl;
    cout << "room:" << stu1.room << endl;

    const Student stu2(2,80);
    cout << "id:" << stu2.getid() << endl;
    cout << "score:" << stu2.getscore() << endl;
    cout << "room:" << stu2.room << endl;
    return 0;
}

***

#include <iostream>
using namespace std;

class Student {
    int id;
    int score;
    static int room;

public:
    static int getroom(){
         return room;
    }

    static void setroom(int newroom){
        room=newroom;
    }

    Student(int newid, int newscore):id(newid){
        score=newscore;
    }

    int getid() const{
        return id;
    }

    int getscore() const{
         return score;
    }

    void setscore(int newscore){
        score=newscore;
    }
};

int Student::room=0;

int main()
{
	Student::setroom(202);
    Student stu1(1,90);
    cout << "id:" << stu1.getid() << endl;
    cout << "score:" << stu1.getscore() << endl;
    cout << "room:" << stu1.getroom() << endl;

    const Student stu2(2,80);
    cout << "id:" << stu2.getid() << endl;
    cout << "score:" << stu2.getscore() << endl;
    cout << "room:" << stu2.getroom() << endl;
    return 0;
}

***

#include <iostream>
#include <cstring>

using namespace std;

class Student {
    static Student * vip;
	char name[100];
	Student(char const  * text) 
	{
		strcpy(name, text);
	}

public:
    static Student * enter(char const  * text)
	{
		if(vip==NULL)
		{
			cout << text << " is vip" << endl;
			vip = new Student(text);
		}
        else
			cout << "Sorry, " << text << ", no more vip" << endl;
		return vip;
    }
	
	void hello()
	{
		cout << "Hello, I'm " << name << endl;
	}
};

Student * Student::vip=NULL;

int main()
{
	Student *stu1,*stu2,*stu3;
	stu1=Student::enter("zhangsan");
	stu2=Student::enter("lisi");
	stu3=Student::enter("wangwu");
	stu1->hello();
	stu2->hello();
	stu3->hello();

    return 0;
}
