#include <iostream>
using namespace std;

class student {
    int id;
    int score;

public:
    student(int newid){
		id=newid;
    }

    int getid(){
        return id;
    }

    int getscore(){
         return score;
    }

    void setscore(int newscore){
        score=newscore;
    }
};
int main()
{
    student s1(1);
	s1.setscore(90);
    cout << "id:" << s1.getid() << endl;
    cout << "score:" << s1.getscore() << endl;

	cout << endl;

    student s2(2);
	s2.setscore(80);
    cout << "id:" << s2.getid() << endl;
    cout << "score:" << s2.getscore() << endl;
    return 0;
}
