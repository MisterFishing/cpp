#include <iostream>
using namespace std;

class Student {
    int id;
    int score;

public:
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
int main()
{
    Student stu1(1,90);
    cout << "id:" << stu1.getid() << endl;
    cout << "score:" << stu1.getscore() << endl;

    const Student stu2(2,80);
    cout << "id:" << stu2.getid() << endl;
    cout << "score:" << stu2.getscore() << endl;
    return 0;
}

