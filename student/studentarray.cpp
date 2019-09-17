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
	// student array
    student sa[3]={student(1),student(2),student(3)};
    sa[0].setscore(90);
    sa[1].setscore(80);
    sa[2].setscore(70);

    for(int i=0;i<3;i++){
        cout << "id:" << sa[i].getid() << endl;
        cout << "score:" << sa[i].getscore() << endl;
        cout << endl;
    }

    return 0;
}
