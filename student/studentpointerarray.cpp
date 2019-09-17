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
	// student pointer array
    student *spa[3];
    for(int i=0;i<3;i++){
        spa[i]=new student(i+1);
        spa[i]->setscore(90-10*i);
    }

    for(int i=0;i<3;i++){
        cout << "id:" << spa[i]->getid() << endl;
        cout << "score:" << spa[i]->getscore() << endl;
        cout << endl;
    }

    return 0;
}
