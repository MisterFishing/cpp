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

class studentnode {
public:
    student s;
    studentnode *next;
    studentnode(int newid):s(newid){
        next=NULL;
    }
};

int main()
{
	studentnode zero(0);

	// student list
    studentnode *sl=&zero;
    studentnode *tmp;

    for(int i=1;i<=3;i++){
        tmp=new studentnode(i);
        tmp->s.setscore(100-10*i);
        tmp->next=sl;
        sl=tmp;
    }

    for(tmp=sl;tmp->next!=NULL;tmp=tmp->next){
        cout << "id:" << tmp->s.getid() << endl;
        cout << "score:" << tmp->s.getscore() << endl;
        cout << endl;
    }

    return 0;
}
