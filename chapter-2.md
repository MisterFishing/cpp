# 面向对象

摇狗尾巴：面向过程

狗摇尾巴：面向对象

物质世界由不同种类的实体构成，不同的实体拥有不同的属性，能够执行不同的动作。

在C++中，用“类”表示种类，用“对象”表示实体，用“成员变量”表示属性，用“成员函数”表示动作。

采用面向对象的方法，能够让程序设计更加贴近于现实世界和日常生活，从而提高软件开发的效率和质量。

面向对象的三大特征：

1. 封装
2. 继承
3. 多态

# 封装

可从两个方面来理解封装：

1. 组合
2. 隐藏

## struct

如果仅从组合的角度来看，C语言的struct已具备一定程度的封装功能。

```
#include <stdio.h>
#include <stdlib.h>
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
```

但是，struct的所有字段，都是公开的，任何人都可以随意读写，这可能带来两个方面的问题：

1. 易用性问题

使用者需要了解太多struct的细节，才能用好这个struct。

2. 安全性问题

无法确保使用者按照正确的方式使用struct。

```
strcpy(zs.name,"zhangsansansan");
zs.number = -1;
zs.score = 200;
```

如何解决？

```
void set_name(struct student *stu, char const *text) 
{
    if(strlen(text)>=10) 
    {
        printf("length of %s >= 10 \n", text);
        exit(0);
    }

    strcpy(stu->name,text);
}

...
// strcpy(zs.name,"zhangsan"); 
set_name(&zs, "zhangsansansan");
...

```

定义新的函数：set_name、set_number、set_score……

仍然不能阻止使用者直接访问：zs.name、zs.number、zs.score……

这是因为C语言没有提供“隐藏”的功能。

真正的“隐藏”，可以解决上述两个问题：

1. 易用性问题

只“公开”必要的信息，其它信息全部“隐藏”起来。使用者只需要了解必要的信息，就能用好“这个东西”。

2. 安全性问题

只“公开”正确的使用方式，其它的方式全部“隐藏”起来。使用者只能通过正确的方式使用“这个东西”。

“这个东西”就是：class。

## class

C++的class，把需要公开的部分和需要隐藏的部分区分开来，分别通过public和private说明。

```
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

    char const * get_name() 
	{
        return name;
    }

    void set_name(char const * text) 
	{
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }
		
        strcpy(name,text);
    }
	
};

int main()
{
    student zs;

	zs.set_name("zhangsan");
    zs.number = 1;
    zs.score = 90;	
	
    cout << zs.get_name() << " " << zs.number << " " << zs.score  << endl;
    return 0;
}
```

name被隐藏起来，只能通过zs.get_name()和zs.set_name()访问，不能直接通过zs.name访问。

可以用相同的方法，把zs.number、zs.score隐藏起来。

无论是变量还是函数，只要放到private区，都会被隐藏，class内可以访问，class外不能访问。

无论是变量还是函数，只要放到public区，都会被公开，class内外都可以访问。

## class vs struct

1. 组合

C的struct只能把变量组合起来，每个变量称为一个“字段”。

C++的class可以把变量和函数组合起来，每个变量称为一个“成员变量”，每个函数称为一个“成员函数”。“成员变量”和“成员函数”统称为“类成员”。

2. 隐藏

C的struct不具备隐藏的功能，使用者可以访问所有“字段”。

C++的class具备隐藏功能，可以把需要公开的“类成员”放到public区，供使用者使用；把需要隐藏的“类成员”放到private区，对使用者透明。

为了提供兼容性，C++也支持struct，但它的功能在原先struct的基础上有所扩展，更加接近于class。

【C++中struct与class的区别与比较】

https://blog.csdn.net/weixin_39640298/article/details/84349171

## class vs object

class是特殊的数据类型，和其它数据类型（如：int、float、struct、……）一样，class可以用来定义变量。使用一个数据类型来定义变量，称为对该数据类型的实例化。定义出来的每一个变量，都称为该数据类型的一个实例（instance ）。

```
int a,b,c;
struct student zs,ls,ww;
```

我们用一个特殊的术语来称呼class（类）的实例，这个术语就是——object（对象）。

```
class student { ... }
student zs,ls,ww;
```

客观世界中存在很多不同类型的实体，每一个实体对应一个object（对象）。同一种类型的实体，具备相同的特征，这些特征，对应一个class（类）。

所以，class（类）和object（对象）是对客观世界的类型和实体的抽象描述，使用面向对象的方法，可以设计出更加接近于客观世界的程序代码。

例子：旺财是一只狗，狗这种类型都拥有尾巴这个属性，并且能够执行摇尾巴这个动作，所以，狗是一个class（类），旺财是一个object（对象）。

```
class dog {

	/* 私有，别人不能碰 */
	private:
	char tail[10]="\n~~~\n"; 

	/* 公有，别人可以调用 */
	public: 
	void wag()
	{ 
		cout << tail;
	}
	
	/* 注：这里的“别人”，是指dog以外的代码 */
};

...

dog wangcai;
cout << wangcai.tail; 	/* 错误：“别人”不能访问私有成员 */
wangcai.wag();			/* 正确：“别人”可以访问公有成员 */
```

# 初始化

每个变量都对应一段内存空间，在定义变量的时候，可以对这段内存空间进行初始化。注意，初始化只有一次机会，就是在定义这个变量的时候。

如果在定义变量的时候不进行初始化，则该变量（对应的内存空间）的值是随机的，直到第一次为该变量赋值。

```
int a;
int b;
cout << a << " " << b << endl;

a=1;
b=2;
cout << a << " " << b << endl;
```

在定义变量的时候，可以使用括号或赋值符号对变量进行初始化操作。

```
int a(0);
int b=0;
cout << a << " " << b << endl;

a=1;
b=2;
cout << a << " " << b << endl;
```

同样，如果在定义对象的时候不进行初始化，则该对象的各个成员变量（对应的内存空间）的值是随机的，直到第一次为该对象的各个成员变量赋值。

```
student ls;
cout << ls.get_name() << " " << ls.number << " " << ls.score  << endl;

ls.set_name("lisi");
ls.number = 2;
ls.score = 80;	

cout << ls.get_name() << " " << ls.number << " " << ls.score  << endl;
```

在定义对象的时候，可以使用括号或赋值符号对这个对象进行初始化。

可以使用已有的对象，对新的对象进行初始化。这样的方式初始化出来的新对象，和原对象是一模一样的。

```
student ls(zs);
cout << ls.get_name() << " " << ls.number << " " << ls.score  << endl;

student ww=zs;
cout << ww.get_name() << " " << ww.number << " " << ww.score  << endl;
```

也可以使用自定义的“构造函数”，实现其它的初始化方法，以满足不同的初始化需求。

构造函数，是一种特殊的成员函数，函数名和类名完全相同，没有返回类型。可以根据需求定义多个构造函数，它们之间通过不同的参数区分（重载构造函数）。

    class student
    {
    	... 
    	
    	student()
        {
            cout << "In student()" << endl;
            
            strcpy(name,"none");
            number=0;
            score=0;      
        }
        
        student(char const * text)
        {
            cout << "In student(char const * text)" << endl;
            
            if(strlen(text)>=10) 
    		{
                cout << "length of " << text << " >= 10 " << endl;
                exit(0);
            }
    
            strcpy(name,text);     
        }   
        
        student(char const * text, int n, int s)
        {
            cout << "In student(char const * text, int n, int s)" << endl;
            
            if(strlen(text)>=10) 
    		{
                cout << "length of " << text << " >= 10 " << endl;
                exit(0);
            }
    
            strcpy(name,text);     
            number=n;
            score=s;        
        }
        
    	...
    	
    }
构造函数在定义对象时调用，如果有多个构造函数，编译器根据参数的个数和类型确定选用哪一个构造函数。

```
student zs;
student ls("lisi",2,80);
student ww("wangwu");

/* or */

student zs={};
student ls={"lisi",2,80};
student ww={"wangwu"};

/* or */
student zs=student();
student ls=student("lisi",2,80);
student ww=student("wangwu");
```

如果不自定义任何构造函数，编译器会提供一个默认的不带任何参数的构造函数，这个构造函数不会对成员变量进行任何操作。一旦有了自定义的构造函数，这个默认的构造函数就失效了。例如，

```
student zs;
```

在自定义构造函数之前，调用的是默认的构造函数。在自定义构造函数之后，默认的构造函数就失效了，调用的是自定义的构造函数。

```
student()
{
    strcpy(name,"none");
    number=0;
    score=0;      
}
```

另外，编译器还提供了另一个默认的构造函数，叫做“复制构造函数”或“拷贝构造函数”。该构造函数的原型如下：

```
student(student & s);
```

这个构造函数带一个参数，参数的类型是这个类的引用类型。

当使用一个已有的对象，对新的对象进行初始化时，就会调用默认的“拷贝构造函数”。默认的“拷贝构造函数”会采用“位拷贝”的方式来初始化新的对象，所以初始化出来的新对象和原对象是一模一样的。

```
student ls(zs);
cout << ls.get_name() << " " << ls.number << " " << ls.score  << endl;

student ww=zs;
cout << ww.get_name() << " " << ww.number << " " << ww.score  << endl;
```

也可以不使用默认的“拷贝构造函数”，而使用自定义的“拷贝构造函数”。

```
student(student & s)
{
    cout << "In student(student & s)" << endl;

    strcpy(name,s.name);
    number=s.number;
    score=s.score;
}
```

一旦有了自定义的“拷贝构造函数”，默认的“拷贝构造函数”就失效了。

当使用上述自定义的“拷贝构造函数”时，以下代码会出现什么问题？

```
student zs=student();
student ls=student("lisi",2,80);
student ww=student("wangwu");
```

***回顾：左值 vs 右值***

修改自定义的“拷贝构造函数”

```
student(student const & s)
{
    cout << "In student(student & s)" << endl;

    strcpy(name,s.name);
    number=s.number;
    score=s.score;
}
```

思考：默认的“拷贝构造函数”已经能够完成拷贝对象的工作了，为什么还需要自定义的“拷贝构造函数”？

# 扫尾

如果一个指针变量指向了一段动态分配的内存空间，在释放指针变量时，系统只会释放该指针变量本身（4字节），不会自动释放它指向的内存空间。

```
#include <iostream>
using namespace std;

void func(int i)
{
    char *p;
    p=new char[1000000];
    cout  << i << endl;
}

int main()
{
    for(int i=1; i<=4000; i++){
        func(i);
    }

    cout << "OK" << endl;
    return 0;
}
```

同样，如果一个对象中存在指针类型的成员变量，在释放该对象时，系统只会释放指针变量本身，不会自动释放它指向的动态分配的内存空间。

```
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
    char * resume;

    student()
    {
        strcpy(name,"none");
        number=0;
        score=0;      
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }

    student(char const * text)
    {
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }

        strcpy(name,text); 
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }   
        
    student(char const * text, int n, int s)
    {
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }

        strcpy(name,text);     
        number=n;
        score=s;
        resume=new char[1000000];   
        strcpy(resume, "Good Boy! ......");        
    }

    char const * get_name() 
	{
        return name;
    }

    void set_name(char const * text) 
	{
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }
		
        strcpy(name,text);
    }
    
    void display()
    {
        cout << name << " " << number << " " << score << " " <<  resume << endl;
    }
};

void func(int i)
{
    student zs("zhangsan",1,90);
    cout  << i << endl;
}

int main()
{
    for(int i=1; i<=4000; i++){
        func(i);
    }
    
    cout << "OK" << endl;
    return 0;
}
```

所以，需要在释放对象的时候执行一些“扫尾”工作，以释放动态分配的内存空间。这个“扫尾”工作就是由“析构函数”完成的。

析构函数也是一种特殊的成员函数，函数名是在类名前面加一个~号，没有返回类型，也没有参数。析构函数不能重载，每个类只有一个析构函数。析构函数在释放对象时调用，可用于释放动态申请的内存空间或其它“扫尾”工作。

```
class student
{
	...
	
    ~student()
    {
        delete[] resume;
    }
    
	...

}
```

不同的对象在释放的时候，都会调用自己的析构函数。

```
void func(int i)
{
    student zs("zhangsan",1,90);
    student ls("lisi",2,80);
    cout  << i << endl;
}
```

思考：以下代码会出现什么问题？

```
void func(int i)
{
    student zs("zhangsan",1,90);
    student ls(zs);
    cout  << i << endl;
}
```

***补充：浅拷贝 vs 深拷贝***

普通变量的拷贝：

```
int a;
a=1;
cout << a << endl;

int b;
b=a;
cout << b << endl;
```

指针的拷贝：

```
char *p1;
p1=new char[1000000];
strcpy(p1,"hello");
cout << p1 << endl;

char *p2;
p2=p1;
cout << p2 << endl; 

/* or */

char *p2;
p2=new char[1000000];
strcpy(p2,p1);
cout << p2 << endl; 
```

两者都实现了指针的拷贝，但前者是拷贝指针本身的值，并没有拷贝指针指向的内容（浅拷贝）；后者是拷贝指针指向的内容（深拷贝）。对浅拷贝来说，对一个指针指向的内容的进行操作，会对另一个指针产生影响；对深拷贝来说，对一个指针指向的内容进行操作，不会对另一个指针造成影响。

```
strcpy(p1,"world");
cout << p2 << endl;   
```

更大的影响，可能出现在释放内存的时候。

```
delete[] p1;
delete[] p2;
cout << "OK" << endl;
```

当使用一个已有的对象，对新的对象进行初始化时，默认的“拷贝构造函数”会采用“位拷贝”的方式来初始化新的对象。如果成员变量中有指针类型的变量，默认的“拷贝构造函数”只能达到“浅拷贝”的效果。如果需要达到“深拷贝”的效果，就需要使用自定义的“拷贝构造函数”，并确保真正执行了“深拷贝”。

```
student(student const & s)
{
    strcpy(name,s.name);
    number=s.number;
    score=s.score;
    
    /* error */
    resume=s.resume; 

    /* correct */
    resume=new char[1000000];
    strcpy(resume,s.resume);     
}
```

完整的代码如下。

```
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
    char * resume;

    student()
    {
        strcpy(name,"none");
        number=0;
        score=0;      
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }

    student(student const & s)
    {
        strcpy(name,s.name);
        number=s.number;
        score=s.score;
        resume=new char[1000000];
        strcpy(resume,s.resume);     
    }
    
    student(char const * text)
    {
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }

        strcpy(name,text); 
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }   
        
    student(char const * text, int n, int s)
    {
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }

        strcpy(name,text);     
        number=n;
        score=s;
        resume=new char[1000000];   
        strcpy(resume, "Good Boy! ......");        
    }

    ~student()
    {
        delete[] resume;
    }
    
    char const * get_name() 
	{
        return name;
    }

    void set_name(char const * text) 
	{
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }
		
        strcpy(name,text);
    }
    
    void display()
    {
        cout << name << " " << number << " " << score << " " <<  resume << endl;
    }
};

void func(int i)
{
    student zs("zhangsan",1,90);
    student ls(zs);
    cout  << i << endl;
}

int main()
{
    for(int i=1; i<=4000; i++){
        func(i);
    }
    
    cout << "OK" << endl;
    return 0;
}
```

# 数组

数组的定义

```
/* 普通数组 */
int a[3];

/* 对象数组 */
student stu[3];
```

数组的使用

```
/* 普通数组 */
a[0]=0;
for(int i=0; i<3; i++)
{
	cout << a[i] << endl;
}

/* 对象数组 */
stu[0].set_name("zhangsan");
stu[0].number = 1;
stu[0].score = 90;	

for(int i=0; i<3; i++)
{
	stu[i].display();
}

```

数组的初始化

```
/* 普通数组 */
int a[3] = { 0, 1, 2 };
for(int i=0; i<3; i++)
{
	cout << a[i] << endl;
}

/* 对象数组 */
student stu[3] = { {}, {"lisi",2,80}, {"wangwu"} };
for(int i=0; i<3; i++)
{
	stu[i].display();
}

/* or */
student stu[3] = { student(), student("lisi",2,80), student("wangwu") };
for(int i=0; i<3; i++)
{
	stu[i].display();
}
```

# 指针

指针的定义

```
/* 普通指针 */
int *ip;

/* 对象指针 */
student *sp;
```

指针的使用

```
/* 普通指针 */
int i(100);
ip = &i;
cout << *ip << endl;

/* 对象指针 */
student zs("zhangsan",1,90);
sp = &zs;
sp->display(); // (*sp).display(); 
```

指向动态分配的内存

```
/* 普通指针 */
ip = new int(200);
cout << *ip << endl;
delete ip;

/* 对象指针 */
sp = new student("lisi",2,80);
sp->display(); // (*sp).display();
delete sp;
```

指向数组元素，以指针的形式访问

```
/* 普通指针 */
int ia[3]={ 1, 2, 3 }; 
ip=ia;
for(int i=0; i<3; i++)
{
    cout << *ip << endl;
    ip++; // ip = ip + 1;
}
cout << *(ip-3) << endl;

/* 对象指针 */
student stu[3] = { {"zhangsan",1,90 }, {"lisi",2,80}, {"wangwu",3,70} };
sp = stu;
for(int i=0; i<3; i++)
{
    sp->display(); // (*sp).display();
    sp++; // sp = sp + 1;
}
(sp-3)->display();
```

指向数组元素，以数组的形式访问

```
int ia[3]={ 1, 2, 3 }; 
ip=ia;
for(int i=0; i<3; i++)
{
    cout << ip[i] << endl;
}

student stu[3] = { {"zhangsan",1,90 }, {"lisi",2,80}, {"wangwu",3,70} };
sp = stu;
for(int i=0; i<3; i++)
{
    sp[i].display();
}
```

上述实例，都是从一个对象的外部，通过指针访问该对象。

有的时候，需要从一个对象的内部，通过指针访问该对象。

这是通过this指针实现的。

```
student(char const * text, int n, int s)
{
    if(strlen(text)>=10) 
    {
        cout << "length of " << text << " >= 10 " << endl;
        exit(0);
    }

    strcpy(this->name,text);     
    this->number=n;
    this->score=s;
    this->resume=new char[1000000];   
    strcpy(this->resume, "Good Boy! ......");        
}
```

默认情况下，编译器会自动补充this指针（定义参数和访问对象成员的时候），所以一般不需要明确的写出来。但是，在有的情况下，需要把this指针明确的写出来。

```
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
    this->resume=new char[1000000];   
    strcpy(this->resume, "Good Boy! ......");        
}
```

完整的代码如下。

```
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
    char * resume;

    student()
    {
        strcpy(name,"none");
        number=0;
        score=0;      
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }

    student(student const & s)
    {
        strcpy(name,s.name);
        number=s.number;
        score=s.score;
        resume=new char[1000000];
        strcpy(resume,s.resume);     
    }
    
    student(char const * text)
    {
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }

        strcpy(name,text); 
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }   
        
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
        this->resume=new char[1000000];   
        strcpy(this->resume, "Good Boy! ......");        
    }

    ~student()
    {
        delete[] resume;
    }
    
    char const * get_name() 
	{
        return name;
    }

    void set_name(char const * text) 
	{
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }
		
        strcpy(name,text);
    }
    
    void display()
    {
        cout << name << " " << number << " " << score << " " <<  resume << endl;
    }
};

int main()
{
    student zs("zhangsan",1,90);
    zs.display();

    student ls("lisi");
    ls.display();
    
    return 0;
}
```

通过调试器可观察到编译器自动补充的this指针。

```
(gdb) bt
#0  student::student (this=0x61fea8,
    name=0x40405a <std::piecewise_construct+22> "zhangsan", number=1, score=90) at test.cpp:48
#1  0x004015f8 in main () at test.cpp:90

(gdb) bt
#0  student::student (this=0x61fe90,
    text=0x404063 <std::piecewise_construct+31> "lisi") at test.cpp:35
#1  0x00401616 in main () at test.cpp:93
```

# 参数传递

普通变量作为参数

```
// 整型变量
void swap(int x, int y)
{
    int tmp;
    tmp=x;
    x=y;
    y=tmp;
}

// 对象
void swap_number(student s1, student s2)
{
    int tmp;
    tmp = s1.number;
    s1.number = s2.number;
    s2.number = tmp;
}

int main()
{
    student zs("zhangsan",1,90);
    zs.display();

    student ls("lisi", 2, 80);
    ls.display();
    
    swap_number(zs, ls);
    zs.display();
    ls.display();
    return 0;
}
```

指针变量作为参数

```
// 整型指针
void swap(int * x, int * y)
{
    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
}

// 对象指针
void swap_number(student * s1, student  * s2)
{
    int tmp;
    tmp = s1->number;
    s1->number = s2->number;
    s2->number = tmp;
}

int main()
{
    student zs("zhangsan",1,90);
    zs.display();

    student ls("lisi", 2, 80);
    ls.display();
    
    swap_number(&zs, &ls);
    zs.display();
    ls.display();
    return 0;
}
```

引用作为参数

```
// 整型引用
void swap(int & x, int & y)
{
    int tmp;
    tmp=x;
    x=y;
    y=tmp;
}

// 对象引用
void swap_number(student & s1, student  & s2)
{
    int tmp;
    tmp = s1.number;
    s1.number = s2.number;
    s2.number = tmp;
}

int main()
{
    student zs("zhangsan",1,90);
    zs.display();

    student ls("lisi", 2, 80);
    ls.display();
    
    swap_number(zs, ls);
    zs.display();
    ls.display();
    return 0;
}
```

# 友元

可从两个方面来理解封装：

1. 组合
2. 隐藏

安全性 vs 方便性

友元打破了类的权限规则。为一个类设置友元后，该类的所有成员对该友元都是可见的。友元机制提高了方便性，但降低了安全性。

有两种类型的友元：友元函数、友元类。

## 友元函数

```
class student
{
    ...
    friend void display_name(student s);
};

void display_name(student s)
{
    cout << s.name << endl;
}

int main()
{
    student zs("zhangsan",1,90);
    display_name(zs);
    return 0;
}
```

## 友元类

```
class student
{
    ...
    friend class teacher;
};

class teacher
{
    public:
    void check(student s)
    {
        cout << s.name << endl;
        cout << s.number << endl;
        cout << s.score << endl;
    }
};

int main()
{
    student zs("zhangsan",1,90);
    teacher t;
    t.check(zs);
    return 0;
}
```

# 类的组合

一个类的成员变量，可以是普通的数据类型，也可以是类类型。

如果一个成员变量是类类型，称为“类的组合”。

类的组合体现了对象的包含关系。

在使用类的组合时，要特别注意一个对象和它包含的对象的初始化问题。

一个对象的构造函数中可以定义一个成员初始化列表，在该列表中，可以对该对象的成员（包括对象成员）进行初始化。

```
#include <iostream>
#include <string.h>
using namespace std;

class point
{
    public:
    float x,y;
    point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    
    // or
    point(float x, float y):x(x),y(y)
    {
    }    
    
};

class circle
{
    public:
    point center;
    float radius;
    circle(float x, float y, float r) : center(x,y) 
    {
        radius = r;
    }
    
    // or
    circle(float x, float y, float r) : center(x,y),radius(r)
    {
    }    
};

int main()
{
    circle c(50,60,20);
    cout << c.center.x << endl;
    cout << c.center.y << endl;
    cout << c.radius << endl;
    
    return 0;
}
```

构造函数的调用顺序：先成员，后自己。

析构函数的调用顺序：先自己，后成员。

如果有多个成员，要注意成员之间的先后顺序。

情况很复杂，方法很简单：

```
...
point()
{
    cout << "point" << endl;
}
...
~point()
{
    cout << "~point" << endl;
}  
...
circle() 
{
    cout << "circle" << endl;
}
...
~circle()
{
    cout << "~circle" << endl;
}    
...
```

# 常对象和常成员

***特别注意：初始化 ≠ 修改***

## 常对象

常量：初始化之后，就不能再修改的变量。

```
int a=1;
a=2;

int const b=1;
b=2;  // error
```

常对象：初始化之后，就不能再修改的对象。

```
student zs("zhangsan",1,90);
zs.score=100;

student const ls("lisi");
ls.score=100;  // error
```

对于成员函数，是否会修改对象？

```
student zs("zhangsan",1,90);
zs.display();

student const ls("lisi");
ls.display();  // ???
```

编译器默认会认为所有成员函数都会修改对象。

除非明确指出：本成员函数不会修改对象——常成员函数。

## 常成员函数

把函数声明为常成员函数。

```
void display() const
{
    ...
}
```

作弊会被检查出来。

```
void display() const
{
    ...
    score = 100;  // error
}
```

## 常成员变量

学号是一个学生入学就确定了的（初始化），以后不能再修改。

```
int const number;
```

会出什么问题？

```
#include <iostream>
#include <string.h>
using namespace std;

class student
{
    private:
    char name[10];

    public:
    int const number;
    int score;
    char * resume;

    student():number(0)
    {
        strcpy(name,"none");
        // number=0;
        score=0;      
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }

    student(student const & s):number(s.number)
    {
        strcpy(name,s.name);
        // number=s.number;
        score=s.score;
        resume=new char[1000000];
        strcpy(resume,s.resume);     
    }
    
    student(char const * text):number(0)
    {
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }

        strcpy(name,text); 
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }   
        
    student(char const * name, int number, int score):number(number)
    {
        if(strlen(name)>=10) 
        {
            cout << "length of " << name << " >= 10 " << endl;
            exit(0);
        }

        strcpy(this->name,name);     
        // this->number=number;
        this->score=score;
        this->resume=new char[1000000];   
        strcpy(this->resume, "Good Boy! ......");        
    }

    ~student()
    {
        delete[] resume;
    }
    
    char const * get_name() 
	{
        return name;
    }

    void set_name(char const * text) 
	{
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }
		
        strcpy(name,text);
    }
    
    void display() const
    {
        cout << name << " " << number << " " << score << " " <<  resume << endl;
    }
};

int main()
{
    student zs("zhangsan",1,90);
    // zs.number=2;
    zs.display();

    student const ls("lisi");
    // ls.number=2;
    ls.display();

    return 0;
}
```

常成员变量必须初始化，且只能在构造函数的成员初始化列表中进行初始化。

合理使用常对象和常成员，能够增强程序的安全性和可控性。

# 静态成员

## 静态成员变量

所有对象共享的数据，可设为静态变量。静态变量只有一份副本，所以，静态变量属于“类”，而称非静态变量属于“对象”。

对于静态成员变量，类的内部只是“申明”，类的外部才是“定义”。

在定义静态成员变量时，可以进行初始化。

```
class student
{
    public:
    ...
    static char school[10];
    ...
}

char student::school[10] = "UESTC";

int main()
{
    student zs("zhangsan",1,90);
    zs.display();
    cout << zs.school << endl;  // cout << student::school << endl;

    student ls("lisi", 2, 80);
    ls.display();
    cout << ls.school << endl;  // cout << student::school << endl;

    return 0;
}

```

通过调试器可观察到静态成员变量的地址。

```
(gdb) p &student::school
$2 = (char (*)[10]) 0x403008 <student::school>
(gdb) p sizeof(student::school)
$3 = 10
(gdb) p &zs
$4 = (student *) 0x61fea8
(gdb) p sizeof(zs)
$5 = 24
(gdb) p &ls
$6 = (student *) 0x61fe90
(gdb) p sizeof(ls)
$7 = 24
```

所以，静态成员变量不属于“对象”，而属于“类”。没有对象，也可以访问静态成员变量。访问的方式是通过“类”。

```
int main()
{
    strcpy(student::school, "uestc");
    cout << student::school << endl;
    return 0;
}
```

## 静态成员函数

编译器不会为静态成员函数自动补充this指针。

```
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
    char * resume;
    static char school[10];
    
    student()
    {
        strcpy(name,"none");
        number=0;
        score=0;      
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }

    student(student const & s)
    {
        strcpy(name,s.name);
        number=s.number;
        score=s.score;
        resume=new char[1000000];
        strcpy(resume,s.resume);     
    }
    
    student(char const * text)
    {
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }

        strcpy(name,text); 
        resume=new char[1000000];
        strcpy(resume, "Good Boy! ......"); 
    }   
        
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
        this->resume=new char[1000000];   
        strcpy(this->resume, "Good Boy! ......");        
    }

    ~student()
    {
        delete[] resume;
    }
    
    char const * get_name() 
	{
        return name;
    }

    void set_name(char const * text) 
	{
        if(strlen(text)>=10) 
		{
            cout << "length of " << text << " >= 10 " << endl;
            exit(0);
        }
		
        strcpy(name,text);
    }
    
    void display()
    {
        cout << name << " " << number << " " << score << " " <<  resume << endl;
    }
    
    static void set_school(char const * text)
    {
        strcpy(school, text);
        // score = 100; 
    }
};

char student::school[10] = "UESTC";

int main()
{
    student::set_school("uestc");
    cout << student::school << endl;
    return 0;
}
```

通过调试器检查编译器是否为静态成员函数补充this指针。

```
(gdb) bt
#0  student::set_school (
    text=0x404045 <std::piecewise_construct+1> "uestc") at test.cpp:90
#1  0x004015e2 in main () at test.cpp:98
```

所以，在不指定对象的情况下，静态成员函数是无法访问对象的普通成员变量的。但是，在不指定对象的情况下，静态成员函数仍然可以访问静态成员变量，因为静态成员变量属于“类”，而不属于“对象”。

```
static void set_school(char const * text)
{
    strcpy(school, text);
    cout << school << endl;
    cout << name << endl; // error
    cout << number << endl; // error
    cout << score << endl; // error
}
```

如果希望用静态成员函数访问普通成员变量，必须指定明确的对象。

```
static void set_school(char const * text)
{
    strcpy(school, text);
    cout << school;
    
    student s;
    cout << s.name;
    cout << s.number;
    cout << s.score;
}
```

## 静态成员的应用

单件模式：一种常见的设计模式。

一般情况下，一个类可以有多个实例（对象）

```
#include <iostream>
#include <string.h>
using namespace std;

class student
{
    private:
    char name[10];
    int number;
    int score;    
    
    public:
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
   
    void display()
    {
        cout << name << " " << number << " " << score << endl;
    }
    
};

int main()
{
    student zs("zhangsan", 1, 90);
    zs.display();

    student ls("lisi", 2, 80);
    ls.display();

    student ww("wangwu ", 3, 70);
    ww.display();
    
    return 0;
}
```

在某些应用场景中，一个类最多只允许一个实例，如何实现？

每创建一个实例，就会调用一次构造函数。

上述构造函数是从类外调用的 or 从类内调用的？

类外调用：使用者调用，不可控。

类内调用：设计者调用，可控。

只允许调用一次，所以不能从类外调用 —— 隐藏构造函数。

```
class student
{
    private:
    student() { ... }
    ...
}
```

隐藏构造函数后，不能从类外调用构造函数。

只能从类内（成员函数中）调用构造函数。

```
class student
{
    private:
    student() { ... }
    ...
    new_student() { ... student() ... }
    ...
}
```

问题1：调用student()前，对象是否存在？

问题2：new_student()属于类 or 对象？

问题3：new_student()应该公开 or 隐藏？

问题4：如何控制student()最多只调用一次？

完整的代码如下。

```
#include <iostream>
#include <string.h>
using namespace std;

class student
{
    private:
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
    char name[10];
    int number;
    int score;
    static student * vip;    

    public:
    static student * new_student(char const * name, int number, int score)
    {
        if(vip==NULL) 
            vip=new student(name, number, score);
        else
            cout << "sorry, only one vip" << endl;
        return vip;   
    }
    
    void display()
    {
        cout << name << " " << number << " " << score << endl;
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
```



