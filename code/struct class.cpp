#include <stdio.h>
#include <string.h>

struct student
{
    char name[10];
    int number;
    int score;
};

int main()
{
    struct student zs;

    strcpy(zs.name,"zhangsan");
    zs.number = 1;
    zs.score = 90;
	
	printf("%s %d %d\n", zs.name, zs.number, zs.score);
    return 0;
}

***

#include <iostream>
#include <string.h>
using namespace std;

class student
{
public:
    char name[10];
    int number;
    int score;
};

int main()
{
    student ls;

    strcpy(ls.name,"lisi");
    ls.number = 2;
    ls.score = 80;	
	
    cout << ls.name << " " << ls.number << " " << ls.score  << endl;
    return 0;
}

***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[10];
    int number;
    int score;
};

void set_name(struct student *stu, char const *text) 
{
	if(strlen(text)>10) 
	{
		printf("Your input seems have some problem. \n");
		exit(0);
	}
	
	strcpy(stu->name,text);
}

int main()
{
    struct student zs;
	char buffer[100];
	
	scanf("%s", buffer);
	set_name(&zs, buffer);
    // strcpy(zs.name,buffer);
    
	zs.number = 1;
    zs.score = 90;
	
	printf("%s %d %d\n", zs.name, zs.number, zs.score);
    return 0;
}

***

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
    student ls;
	char buffer[100];
	
	scanf("%s", buffer);
	ls.set_name(buffer);
    // strcpy(ls.name,buffer);
    ls.number = 2;
    ls.score = 80;	
	
    cout << ls.get_name() << " " << ls.number << " " << ls.score  << endl;
    return 0;
}

