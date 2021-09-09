#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[10];
    int number;
    int score;
};

void set_name(struct student * stu, char const * text) 
{
    if(strlen(text)>=10) 
    {
        printf("length of %s >= 10 \n", text);
        exit(0);
    }

    strcpy(stu->name,text);
}

void set_number(struct student * stu, int num) 
{
    if(num <= 0) 
    {
        printf("number %d <= 0 \n", num);
        exit(0);
    }

    stu->number = num;
}

void set_score(struct student * stu, int score) 
{
    if(score < 0) 
    {
        printf("score %d < 0 \n", score);
        exit(0);
    }

    if(score > 100) 
    {
        printf("score %d > 100 \n", score);
        exit(0);
    }

    stu->score = score;
}

void display(struct student *stu)
{
    printf("%s %d %d\n", stu->name, stu->number, stu->score);
}

int main()
{
    struct student zs;

    set_name(&zs, "zhangsan");
    set_number(&zs, 1);
    set_score(&zs, 90);
	display(&zs);
    return 0;
}
