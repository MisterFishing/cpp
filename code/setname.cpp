#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Student1 {
    char name[10];
    int grade;
    int number;
};

void SetName(struct Student1 *stu, char const *text) {
	if(strlen(text)>10) {
		cout << "Error: name > 10!" << endl;
		exit(1);
	}
	strcpy(stu->name,text);
}

class Student2 {
    private:
    char name[10];

    public:
    int grade;
    int number;

    char* GetName() {
        return name;
    }

    void SetName(char const *text) {
        if(strlen(text)>10) {
            cout << "Name no more than 10!" << endl;
            exit(1);
        }
        strcpy(name,text);
    }
};

int main() {
    struct Student1 a;
    Student2 b;

	SetName(&a, "ZhangSan");
    a.grade = 2017;
    a.number = 3;

    b.SetName("LiSi");
    b.grade = 2017;
    b.number = 4;

    cout << a.name << " " << a.grade << " " << a.number << endl;
    cout << b.GetName() << " " << b.grade << " " << b.number << endl;

    return 0;
}
