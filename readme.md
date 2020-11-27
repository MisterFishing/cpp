# 实验环境

## MinGW-W64

【官网下载】

https://sourceforge.net/projects/mingw-w64/files/

MinGW-W64 GCC-8.1.0

i686-win32-dwarf

文件名：i686-8.1.0-release-win32-dwarf-rt_v6-rev0.7z

解压到任意文件夹，例如：C:\mingw

C++编译器文件：C:\mingw\bin\g++.exe

打开命令提示符，设置环境变量：

```
C:\>setx path "%path%;C:\mingw\bin"

成功: 指定的值已得到保存。

C:\>

```

关闭并重新打开命令提示符，使设置生效。

【官网地址】

http://www.mingw-w64.org

【科普MinGW MinGW-W64】

https://blog.csdn.net/whatday/article/details/87113007

## 编译器：g++

g++ --version

出现版本信息，表示编译器安装成功。

```
C:\>g++ --version
g++ (i686-win32-dwarf-rev0, Built by MinGW-W64 project) 8.1.0
Copyright (C) 2018 Free Software Foundation, Inc.
...

C:\>

```
【官网地址】

https://gcc.gnu.org/onlinedocs/

【GCC参数详解】

https://www.runoob.com/w3cnote/gcc-parameter-detail.html



## 调试器：gdb

gdb --version

出现版本信息，表示调试器安装成功。

```
C:\test>gdb --version
GNU gdb (GDB) 8.1
Copyright (C) 2018 Free Software Foundation, Inc.
...

C:\>
```
【官网文档】

http://www.gnu.org/software/gdb/documentation/

【C++ GDB调试大全】

https://blog.csdn.net/bigheadyushan/article/details/77828949

# 第一个C++程序

```c++
int main()
{
    return 0; /* 1、2、3…… */
}
```

编译：g++ test.cpp -o test.exe

执行：test.exe

查看结果（返回值）：

```
echo %errorlevel%
```

# 第二个C++程序

```c++
#include <stdio.h>
int main()
{
    printf("Hello, I'm a C++ program.\n");
    return 0;
}
```

库函数：printf

头文件：stdio.h

文件路径：C:\tools\mingw\i686-w64-mingw32\include

如何找到：搜索……

# 第三个C++程序

```c++
#include <iostream>
using namespace std;
int main()
{
    cout << "Hello, I'm really a C++ program." << endl;
    return 0;
}
```

输出流对象：cout

头文件：iostream

文件路径：C:\tools\mingw\lib\gcc\i686-w64-mingw32\8.1.0\include\c++

如何找到：搜索……

# C++语言中的I/O

输出流对象：cout

左移运算符：<<

```
int a = 5, b = 4;
printf("a + b = %d \n", a + b);
cout << "a + b = " << a + b << endl; 
```
输入流对象：cin

右移运算符：>>

```
int a, b ;
scanf("%d %d", &a, &b);
cin >> a >> b;
```

【C++ cout格式化输出】

http://c.biancheng.net/view/7578.html

【cin深入分析】

https://blog.csdn.net/lewsn2008/article/details/2295790

https://blog.csdn.net/dongtingzhizi/article/details/2299358

https://blog.csdn.net/lewsn2008/article/details/2299365

# C++语言中的数据类型

## 逻辑类型

```
int i,j;
bool a,b;

a = true;
b = false;
cout << "a = " << a << ", " << "b = " << b << endl;

i=a;
j=b;
cout << "i = " << i << ", " << "j = " << j << endl;

a = !i;
b = !j;
cout << "a = " << a << ", " << "b = " << b << endl;
```

## 引用类型

### 独立引用

引用就是别名。

```
int number = 15;
int & n = number;
n = 18;
cout << number << " " << n << endl;
```

用调试器验证引用就是别名。

如何验证？

```
g++ -g test.cpp -o test.exe
```

---

***补充：程序调试方法***

设置编译选项：-g

启动与退出：run, quit，……

设置断点：break, info, del, enable, disable, watch，……

控制程序执行：next, step, continue, finish, set, call，……

查看程序状态：backtrace, list, print, display, info，……

---

#### 引用的初始化

必须在定义的时候初始化。

```
int a=1, b=2;
int &n = a;
n = b;
n = 3;
cout << a << " " << b << " " << endl;
```

#### 常引用

普通引用不能作为常量的别名，可使用常引用作为常量的别名。

```
const int &n = 1;
```

常引用可以作为常量的别名，也可以作为变量的别名。

```
int a=1;
const int &n = a;
```

无论怎样，常引用的值都不能修改。

```
n = 3; /* 错误 */
```

---

***补充：常量***

常量与宏

```
#define PI 3.14

int main()
{
    float x, y;
    const float pi=3.14;

    x=PI;
    y=pi;
    cout << x << " " << y << endl;

    return 0;
}

```

常量与指针

```
#define PI 3.14

int main()
{
    float x, y;
    const float pi=3.14;

    x=PI;
    y=pi;
    cout << x << " " << y << endl;


	float * const p1=&x;
//	p1=&y;
//	*p1=1.11;

	float const * p2=&x;
//	p2=&y;
//	*p2=1.11;

	float const * const p3=&x;
//	p3=&y;
//	*p3=1.11;

    cout << x << " " << y << endl;

    return 0;
}
```
指针常量（指针类型的常量）—— 别乱指

常量指针（指向常量的指针）—— 别乱动

指向常量的指针常量 —— 别乱指 + 别乱动

---

### 作为函数参数

普通变量作为参数

```
void swap(int x, int y)
{
    int tmp;
    tmp=x;
    x=y;
    y=tmp;
}
```

指针变量作为参数

```
void swap(int * x, int * y)
{
    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
}
```

引用作为参数

```
void swap(int & x, int & y)
{
    int tmp;
    tmp=x;
    x=y;
    y=tmp;
}
```

### 作为函数返回类型

#### 返回普通类型——右值。

```
int x=1;

int f()
{
    x=2;
    return x;
}

int main()
{
    int a=3;
    a = f();
    cout << a << endl;
}
```

右值只能放在赋值符号的右边，因为它代表的，仅仅是一个“值”。

#### 返回引用——左值。

```
int x=1;

int & f()
{
    x=2;
    return x;
}

int main()
{
    int a=3;
    f() = a;
    cout << x << endl;
}
```

左值既可以放在赋值符号的左边，也可以放在赋值符号的右边，因为它代表的是一个“内存单元”。

# C++语言中的内联函数

## 内联函数例子

```
inline int add(int value) 
{
    int x;
    x = value + 1;
    x = x + 2;
    x = x + 3;
    return x;
}

int main()
{
    int a,b;
    cin >> a;
    b=add(a);
    cout << b << endl;
    return 0;
}
```

用调试器检查是否内联成功。

如何检查？

编译优化选项：-O

```
g++ -g -O test.cpp -o test.exe
```

inline仅仅是对编译器的一个优化建议，是否采纳，还看编译器自己。

即使不提这个建议，编译器也会在适当的时候进行优化。

inline在编译优化技术不太成熟的时候，用得较多，现在用得越来越少。

# 函数重载

在编译的过程中，编译器会把函数名在原先的基础上做一些改变。

C程序编译实例：


```
int GetMax2(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int GetMax3(int x, int y, int z)
{
    int tmp1,tmp2;
    tmp1=GetMax2(x,y);
    tmp2=GetMax2(tmp1,z);
    return tmp2;
}

int main()
{
    return 0;
}
```
修改后的函数名：

```
gcc test.c -o test.exe
nm test.exe | find "GetMax"
004015c0 T _GetMax2
004015d5 T _GetMax3
```

C++程序编译实例：


```
int GetMax2(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int GetMax3(int x, int y, int z)
{
    int tmp1,tmp2;
    tmp1=GetMax2(x,y);
    tmp2=GetMax2(tmp1,z);
    return tmp2;
}

int main()
{
    return 0;
}
```

修改后的函数名：

```
g++ test.cpp -o test.exe
nm test.exe | find "GetMax"
004015c0 T __Z7GetMax2ii
004015d5 T __Z7GetMax3iii
```

C++编译器的修改方式，使得源代码中即使使用了两个完全相同的函数名，在编译的过程中也不会发生重名冲突。

但至少需要满足以下两个要求之一：

1. 参数个数不同
1. 参数类型不同

参数个数不同：

```
int GetMax(int x, int y)
int GetMax(int x, int y, int z)
```

修改后的函数名：

```
nm test.exe | find "GetMax"
004015c0 T __Z6GetMaxii
004015d5 T __Z6GetMaxiii
```

参数类型不同：

```
int GetMax(int x, int y)
int GetMax(float x, float y)
```

修改后的函数名：

```
nm test.exe | find "GetMax"
004015d5 T __Z6GetMaxff
004015c0 T __Z6GetMaxii
```

两个以上的函数，具有相同的函数名，但是形参个数或者类型不同。在函数调用的时候，编译器会根据实参的类型及个数的最佳匹配来自动确定调用哪一个函数。

用调试器验证调用了正确的函数。

如何验证？

```
(gdb) b *0x004015c0
Breakpoint 3 at 0x4015c0: file test.cpp, line 5.
(gdb) b *0x004015d5
Breakpoint 4 at 0x4015d5: file test.cpp, line 13.
```

# 带默认形参值的函数

可以在定义函数时给出默认的形参值。调用函数时如果给出了实参值，则使用给出的实参值；如果未给出实参值，则使用默认的形参值。

```
int Register(int number, char const * name, int age=18, char const * country="China")
{
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Country: " << country << endl << endl;
    return 0;
}

int main()
{
    Register(1,"ZhangSan");
    Register(2,"LiSi");
    Register(3,"WangWu", 20);
    Register(4,"Tom", 18, "England");
    return 0;
}
```

## 注意

形参的顺序：无默认值的形参在前，有默认值的形参在后。

与函数重载的关系：本身不是函数重载，但 **“可能”** 会和函数重载相互影响。

编译器处理函数调用时，如果不能确定该调用哪个函数，则会出现编译错误；如果能够确定该调用哪个函数，则不会出现编译错误。

```
int Register(int number, char const * name, int age=18, char const * country="China")
{
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Country: " << country << endl << endl;
    return 0;
}

int Register(int number, char const * name)
{
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << 18 << endl;
    cout << "Country: " << "China" << endl << endl;
    return 0;
}

int main()
{
    Register(1,"ZhangSan"); /* error */
    Register(2,"LiSi"); /* error */
    Register(3,"WangWu", 20); 
    Register(4,"Tom", 18, "England"); 
    return 0;
}
```

# 动态内存分配和释放

C语言的动态内存分配和释放使用***函数***：malloc()、free()等，它们来自标准函数库。

```
#include <stdlib.h>

int main()
{
    int * a;
    a = malloc(sizeof(int));
    free(a);
    return 0;
}
```

C++语言的动态内存分配和释放使用***运算符***：new、delete，它们是语言的组成部分。

```
int main()
{
    int * a;
    a = new int;
    delete a;
    return 0;
}
```

## 使用方法

方法1：

分配和释放一个变量的空间

type *p; p=new type; delete p;

```
int main()
{
    int * a;
    a = new int;
    *a = 123;
    cout << *a;
    delete a;
    return 0;
}
```
方法2：

分配和释放一个变量的空间，并赋予初值。

type *p; p=new type(x); delete p;


```
int main()
{
    int * a;
    a = new int(456);
    cout << *a;
    delete a;
    return 0;
}
```

方法3：

分配和释放多个变量（一个数组）的空间。

type *p; p=new type[x]; delete []p;

```
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char * a;
    a = new char[10];
    strcpy(a,"hello");
    cout << a;
    delete []a;
    return 0;
}
```

未delete或多次delete，都可能导致程序崩溃。

```
#include <iostream>
using namespace std;

void func(int i)
{
    char *p;
    p=new char[1000000];
    cout  << i << endl;
    delete []p;
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

# 面向过程与面向对象

## 摇狗尾巴

面向过程

## 狗摇尾巴

面向对象

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



# 继承

## 多个相似的类

```
#include <iostream>
#include <cstring>

using namespace std;

class animal 
{
	public:
	
	char name[8];
    
    animal(const char * name) 
	{
        strncpy(this->name, name, 7);
        this->name[7]='\0';
    }

    void say_hello() 
	{
        cout << "Hello" << endl;
    }

    void my_name() 
	{
        cout << "My name is "<< name << endl;
    }
    
};

class dog
{
	public:
    
    char name[8];
	int birth;

    dog(const char * name, int birth) 
	{
        strncpy(this->name, name, 7);
        this->name[7]='\0';
        this->birth=birth;
    }

    void say_hello() 
	{
        cout << "Wang Wang" << endl;
    }
    
    void my_name() 
	{
        cout << "My name is "<< name << endl;
    }

    void my_birth() 
	{
        cout << "I born in " << birth << endl;
    } 
};

class cat
{
	public:
    
    char name[8];
	char color[8];

    cat(const char * name, const char * color) 
	{
        strncpy(this->name, name, 7);
        this->name[7]='\0';

        strncpy(this->color, color, 7);
        this->color[7]='\0';
    }

    void say_hello() 
	{
        cout << "Miao Miao" << endl;
    }
    
    void my_name() 
	{
        cout << "My name is "<< name << endl;
    }

    void my_color() 
	{
        cout << "I am " << color << endl;
    }
};

int main()
{
    animal a("Animal");
    a.say_hello();
    a.my_name();

    dog b("WangCai", 2020);
    b.say_hello();
    b.my_name();
    b.my_birth();
      
    
    cat c("JiaFei", "BLACK");
    c.say_hello();
    c.my_name();
    c.my_color();

    return 0;
}
```

## 基类与派生类

重用：name, my_name()

改造：say_hello()

扩充：birth, my_birth(),  color, my_color()

从animal到dog/cat：派生或继承

animal：基类

dog、cat：派生类

```
#include <iostream>
#include <cstring>

using namespace std;

class animal 
{
	public:
	
	char name[8];
    
    animal(const char * name) 
	{
        strncpy(this->name, name, 7);
        this->name[7]='\0';
    }

    void say_hello() 
	{
        cout << "Hello" << endl;
    }

    void my_name() 
	{
        cout << "My name is "<< name << endl;
    }
    
};

class dog : public animal
{
	public:
    
	int birth;

    dog(const char * name, int birth) : animal(name) 
	{
        this->birth=birth;
    }

    void say_hello() 
	{
        cout << "Wang Wang" << endl;
    }
    
    void my_birth() 
	{
        cout << "I born in " << birth << endl;
    } 
};

class cat : public animal
{
	public:
    
	char color[8];

    cat(const char * name, const char * color) : animal(name) 
	{
        strncpy(this->color, color, 7);
        this->color[7]='\0';
    }

    void say_hello() 
	{
        cout << "Miao Miao" << endl;
    }
    
    void my_color() 
	{
        cout << "I am " << color << endl;
    }
};

int main()
{
    animal a("Animal");
    a.say_hello();
    a.my_name();

    dog b("WangCai", 2020);
    b.say_hello();
    b.my_name();
    b.my_birth();
    
    cat c("JiaFei", "BLACK");
    c.say_hello();
    c.my_name();
    c.my_color();

    return 0;
}
```

通过调试器查看基类对象、派生类对象的内存空间分配情况

对象的值、大小、地址、成员变量、成员函数

```
(gdb) p a
(gdb) p sizeof(a)
(gdb) p &a
(gdb) p &a.name
... b or c
(gdb) p a.my_name
(gdb) p b.my_name
(gdb) p c.my_name
... 
(gdb) p a.say_hello
(gdb) p b.say_hello
(gdb) p c.say_hello
...
```

如何访问作用域被覆盖的成员变量/成员函数？

```
b.say_hello();
b.dog::say_hello();
b.animal::say_hello();

c.say_hello();
c.cat::say_hello();
c.animal::say_hello();
```

构造函数/析构函数及其调用顺序。

```
#include <iostream>
#include <cstring>

using namespace std;

class animal 
{
	public:
	
	char name[8];
    
    animal(const char * name) 
	{
        cout << "animal(): " << name << endl;
        strncpy(this->name, name, 7);
        this->name[7]='\0';
    }

    ~animal() 
	{
        cout << "~animal(): " << name << endl;
    }
    
    void say_hello() 
	{
        cout << "Hello" << endl;
    }

    void my_name() 
	{
        cout << "My name is "<< name << endl;
    }
    
};

class dog : public animal
{
	public:
    
	int birth;

    dog(const char * name, int birth) : animal(name) 
	{
        cout << "dog():" << name << endl;
        this->birth=birth;
    }

    ~dog() 
	{
        cout << "~dog():" << name << endl;
    }
    
    void say_hello() 
	{
        cout << "Wang Wang" << endl;
    }
    
    void my_birth() 
	{
        cout << "I born in " << birth << endl;
    } 
};

class cat : public animal
{
	public:
    
	char color[8];

    cat(const char * name, const char * color) : animal(name) 
	{
        cout << "cat():" << name << endl;
        strncpy(this->color, color, 7);
        this->color[7]='\0';
    }

    ~cat() 
	{
        cout << "~cat():" << name << endl;
    }
    
    void say_hello() 
	{
        cout << "Miao Miao" << endl;
    }
    
    void my_color() 
	{
        cout << "I am " << color << endl;
    }
};

int main()
{
    animal a("Animal");
    a.say_hello();
    a.my_name();

    dog b("WangCai", 2020);
    b.say_hello();
    b.my_name();
    b.my_birth();
    
    cat c("JiaFei", "BLACK");
    c.say_hello();
    c.my_name();
    c.my_color();

    return 0;
}
```

## 访问权限控制

能够继承，不代表能够访问。

以基类中的成员变量name为例，有3个位置可能对它进行访问。

```
char name[8];
```

1. 基类内部

```
void say_hello() 
{
    cout << "Hello" << name << endl;  
}
```

2. 基类外部、派生类内部

```
void say_hello() 
{
	cout << "Wang Wang ... " << name << endl;  
}
```

3. 基类外部、派生类外部

```
dog b("WangCai", 2020);
cout << b.name;
```

是否能访问成功，取决于两点。

1. 基类成员的访问控制属性（public成员、protected成员、private成员）

```
public:
char name[8];

protected:
char name[8];

private:
char name[8];
```

2. 派生类的继承方式（public继承、protected继承、private继承）

```
class dog : public animal { ... }
class dog : protected animal { ... }
class dog : private animal { ... }
```

共 3x3=9 种组合

| 继承方式 | public成员 | protected成员 | private成员 |
|  ----  | ----  | ----  | ----  |
| public继承 | public成员 |protected成员|N/A|
| protected继承 | protected成员 |protected成员|N/A|
| private继承 | private成员 |private成员|N/A|

## 多继承

一个派生类可以有多个基类。

```
class shenshou : public dog, public cat
{
	public:
    shenshou(const char * name, int birth, const char * color) : dog(name,birth) , cat(name, color) 
	{
    }
};
```

以下代码是否正确？

```
shenshou s("ShenShou", 2022, "GOLD");
s.my_birth();
s.my_color();
```

以下代码是否正确？

```
shen_shou s("ShenShou", 2022, "GOLD");
cout << s.name;
s.say_hello();
s.my_name();
```

dog？cat？animal？

如何更加优美的解决问题？

## 虚基类

```
class dog : public virtual animal
class cat : public virtual animal
class shenshou : public dog, public cat
{
	public:
    shenshou(const char * name, int birth, const char * color) : dog(name,birth),cat(name,color),animal(name) 
	{
    }        
};
```

以下代码是否正确？

    shenshou s("ShenShou", 2022, "GOLD");
    cout << s.name << endl;
    s.my_name();
    s.animal::say_hello();
# 多态

多态：一种形式，多种状态

## 多态的类型

静态多态：函数重载、运算符重载、模板

动态多态：虚函数

## 虚函数

快乐的动物园

```
int main()
{
    animal a("Animal");
    dog b("WangCai", 2020);
    cat c("JiaFei", "BLACK");
    
    cout << "--- At home ---" << endl;
    a.say_hello();
    b.say_hello();
    c.say_hello();
	
    cout << "--- At zoo ---" << endl;

    animal *zoo[3]={&a, &b, &c};
    for(int i=0; i<3; i++)
    {
        zoo[i]->say_hello();
    }
    
    return 0;
}
```

问题：只看到animal，没看到dog、cat，缺乏个性

解决方法：虚函数

把基类的成员函数申明为虚函数

```
virtual void say_hello() { ... }
```

为什么能实现这个效果？—— vtable

通过调试器，观察vtable。

```
(gdb) p sizeof(a)
(gdb) p sizeof(b)
(gdb) p sizeof(c)
```

定位多出的空间的地址

```
(gdb) p &a
(gdb) p &a.name
(gdb) p &b
(gdb) p &b.name
(gdb) p &c
(gdb) p &c.name
```

查看该空间的值

```
(gdb) p a
(gdb) p/x *(int *)&a
```

把这个值当作一个地址，查看该地址指向的空间的值

```
(gdb) p *(*(int *)&a)
```

把这个值也当作一个地址来查看

```
(gdb) p (void*)*(*(int *)&a)
... <animal::say_hello()>
(gdb) p a.say_hello
```

同样的方法，查看其它几个对象对应的地址

```
(gdb) p (void*)*(*(int *)&b)
... <dog::say_hello()>
(gdb) p b.say_hello
(gdb) p (void*)*(*(int *)&c)
... <cat::say_hello()>
(gdb) p c.say_hello
```

每个对象有一个vtable

每个vtable中记录了这个对象可用的虚函数的地址

say_hello是第1个虚函数

***思考：***

当存在第2个虚函数时（如say_hello2()），如何查看？

```
(gdb) p/x *(int *)&a+4
(gdb) p *(*(int *)&a+4)
(gdb) p (void*)*(*(int *)&a+4)
(gdb) x *(int *)&a
(gdb) x/2 *(int *)&a
(gdb) x/2xw *(int *)&a
```

当存在第3个、第4个……虚函数时，如何查看？

如果有多只dog或多只cat，结果会如何？

完整的代码如下。

```
#include <iostream>
#include <cstring>

using namespace std;

class animal 
{
    public:

    char name[8];

    animal(const char * name) 
    {
        strncpy(this->name, name, 7);
        this->name[7]='\0';
    }

    virtual void say_hello() 
    {
        cout << "Hello" << endl;
    }

    void my_name() 
    {
        cout << "My name is "<< name << endl;
    }

};

class dog : public animal
{
    public:

    int birth;

    dog(const char * name, int birth) : animal(name) 
    {
        this->birth=birth;
    }

    void say_hello() 
    {
        cout << "Wang Wang" << endl;
    }

    void my_birth() 
    {
        cout << "I born in " << birth << endl;
    } 
};

class cat : public animal
{
    public:

    char color[8];

    cat(const char * name, const char * color) : animal(name) 
    {
        strncpy(this->color, color, 7);
        this->color[7]='\0';
    }

    void say_hello() 
    {
        cout << "Miao Miao" << endl;
    }

    void my_color() 
    {
        cout << "I am " << color << endl;
    }
};

int main()
{
    animal a("Animal");
    dog b1("WangCai1", 2021);
    dog b2("WangCai2", 2022);
    cat c1("JiaFei1", "BLACK");
    cat c2("JiaFei2", "WHITE");
    
    cout << "--- At home ---" << endl;
    a.say_hello();
    b1.say_hello();
    b2.say_hello();
    c1.say_hello();
    c2.say_hello();
    
    cout << "--- At zoo ---" << endl;

    animal *zoo[5]={&a, &b1, &b2, &c1, &c2};
    for(int i=0; i<5; i++)
    {
        zoo[i]->say_hello();
    }

    return 0;
}
```

问题1：animal能say_hello吗？

问题2：存在animal类型的对象吗？

直接删除say_hello，有什么问题？

解决方法：纯虚函数

## 纯虚函数

纯虚函数的定义。

```
virtual void say_hello() = 0;
```

完整的代码如下。

```
#include <iostream>
#include <cstring>

using namespace std;

class animal 
{
    public:

    char name[8];

    animal(const char * name) 
    {
        strncpy(this->name, name, 7);
        this->name[7]='\0';
    }

    virtual void say_hello() = 0;

    void my_name() 
    {
        cout << "My name is "<< name << endl;
    }

};

class dog : public animal
{
    public:

    int birth;

    dog(const char * name, int birth) : animal(name) 
    {
        this->birth=birth;
    }

    void say_hello() 
    {
        cout << "Wang Wang" << endl;
    }

    void my_birth() 
    {
        cout << "I born in " << birth << endl;
    } 
};

class cat : public animal
{
    public:

    char color[8];

    cat(const char * name, const char * color) : animal(name) 
    {
        strncpy(this->color, color, 7);
        this->color[7]='\0';
    }

    void say_hello() 
    {
        cout << "Miao Miao" << endl;
    }

    void my_color() 
    {
        cout << "I am " << color << endl;
    }
};

int main()
{
    dog b1("WangCai1", 2021);
    dog b2("WangCai2", 2022);
    cat c1("JiaFei1", "BLACK");
    cat c2("JiaFei2", "WHITE");

    cout << "--- At home ---" << endl;
    b1.say_hello();
    b2.say_hello();
    c1.say_hello();
    c2.say_hello();
    
    cout << "--- At zoo ---" << endl;

    animal *zoo[4]={&b1, &b2, &c1, &c2};
    for(int i=0; i<4; i++)
    {
        zoo[i]->say_hello();
    }

    return 0;
}
```

***抽象类***

拥有纯虚函数的类称为抽象类。

抽象类不能被实例化，只能作为其它类的基类。

***接口类***

当一个抽象类的所有成员函数都是纯虚函数时，这个抽象类又称为接口类。

***抽象类的派生类***

一个抽象类的派生类需要实现这个抽象类的全部纯虚函数，才能被实例化。否则，这个派生类仍然是抽象类，仍然不能实例化。

## 模板

场景：多个函数，功能相似，参数类型不同。

解决方法：函数重载

```
#include <iostream>

using namespace std;

char addone(char x)
{
    cout << "char: ";
    return (x+1);
}

int addone(int x)
{
    cout << "int: ";
    return (x+1);
}

float addone(float x)
{
    cout << "float: ";
    return (x+1);
}

double addone(double x)
{
    cout << "double: ";
    return (x+1);
}

int main()
{
    char x1='a';
    int x2=1;
    float x3=1.1;
    double x4=1.11;
	
    cout << addone(x1) << endl;
    cout << addone(x2) << endl;
    cout << addone(x3) << endl;
    cout << addone(x4) << endl;

    return 0;
}
```

利用强制类型转换，可少写几个函数，减少代码量。

删除第1、2、3个函数……

删除第2、3、4个函数……

删除第2、3个函数……

删除第3个函数……

都不够简化，也不够优雅。

解决方法：函数模板

### 函数模板

```
#include <iostream>

using namespace std;

template <class T>
T addone(T x)
{
    cout << "T: ";
    return (x+1);
}

int main()
{
    char x1='a';
    int x2=1;
    float x3=1.1;
    double x4=1.11;
	
    cout << addone(x1) << endl;
    cout << addone(x2) << endl;
    cout << addone(x3) << endl;
    cout << addone(x4) << endl;

    return 0;
}
```

函数模板最终会被“实例化”为模板函数。

这个“实例化”的过程，是在编译阶段完成的。

一个函数模板，会被“实例化”为多个模板函数 —— 多态。

“实例化”的过程在编译阶段完成，所以这个多态是“静态”的 —— 静态多态。

***对比：函数重载***

一个函数，对应多个实现（多个不同的代码段） —— 多态。

对应过程在编译阶段完成，所以这个多态是“静态”的 —— 静态多态。

函数名与代码段之间的对应：编译时确定，运行不会改变。

用nm观察函数重载的结果。

```
nm test.exe | find "addone"
004015c0 T __Z6addonec
0040162e T __Z6addoned
0040160b T __Z6addonef
004015e9 T __Z6addonei
```

函数模板实例化为模板函数：编译时确定，运行不会改变。

用nm观察函数模板实例化的结果。
```
nm test.exe | find "addone"
004027e0 T __Z6addoneIcET_S0_
0040280c T __Z6addoneIdET_S0_
0040283c T __Z6addoneIfET_S0_
00402860 T __Z6addoneIiET_S0_
```

如果把函数重载，看作你“手动”实现多个功能相似的函数，那么，可以把函数模板，看作编译器“自动”帮你实现多个功能相似的函数。

函数模板可以和函数重载配合使用，适应更加灵活的应用场景。

### 类模板

场景：多个类，功能相似，参数类型不同。

解决方法1：手工实现多个类（不够简化、不够优雅）

解决方法2：使用类模板，让编译器“自动”帮你实现多个类

```
#include <iostream>

using namespace std;

template <class T>
class node
{
    T value;
    node *prev,*next;

	public:

    node()
	{ 
		prev=NULL;
		next=NULL;
	}
    
	void set_value(T value)
	{
		this->value=value;
	}
	
	T get_value()
	{
		return value;
	}
	    
	node * get_prev()
	{
		return prev;
	}

	node * get_next()
	{
		return next;
	}

	void append(node *p)
    {
        p->prev=this;
        if(next!=NULL) next->prev=p;
        p->next=next;
        next=p;
    }

};

int main( )
{
    node<int> *ptr1;
    node<int> n1,n2,n3;
    n1.set_value(97);
    n2.set_value(98);
    n3.set_value(99);
    n1.append(&n2);
	n2.append(&n3);

	for(ptr1=&n1 ; ; ptr1=ptr1->get_next())
	{
		cout << ptr1->get_value() << endl;
		if(ptr1->get_next()==NULL) break;
	}    
    
    node<float> *ptr2;
    node<float> n4,n5,n6;
    n4.set_value(97.5);
    n5.set_value(98.5);
    n6.set_value(99.5);
    n4.append(&n5);
	n5.append(&n6);

	for(ptr2=&n4 ; ; ptr2=ptr2->get_next())
	{
		cout << ptr2->get_value() << endl;
		if(ptr2->get_next()==NULL) break;
	}
	
    return 0;
}
```

用nm观察类模板实例化的结果。

```
nm test.exe | find "node"
004028a0 T __ZN4nodeIfE6appendEPS0_
004028e4 T __ZN4nodeIfE8get_nextEv
004028f8 T __ZN4nodeIfE9get_valueEv
00402908 T __ZN4nodeIfE9set_valueEf
00402920 T __ZN4nodeIfEC1Ev
00402940 T __ZN4nodeIiE6appendEPS0_
00402984 T __ZN4nodeIiE8get_nextEv
00402998 T __ZN4nodeIiE9get_valueEv
004029a8 T __ZN4nodeIiE9set_valueEi
004029c0 T __ZN4nodeIiEC1Ev
```

每个类都拥有自己的构造函数和成员函数版本。

总结：函数模板、类模板，都是由编译器“自动”帮你实现相关代码。

### 标准模板库

泛型程序设计（Generic Programming）是一种程序设计风格，泛型允许程序员在编写代码时使用一些以后才指定的数据类型。《设计模式（Design Patterns）》一书将泛型称为参数化类型（Parameterized Type）。很多程序设计语言和编译器都支持泛型，泛型在不同的程序设计语言中有不同的叫法。

Ada、Delphi、Eiffel、Java、C#、F#、Swift、Visual Basic .NET：泛型（Generics）

ML、Scala、Haskell：参数多态（Parametric Polymorphism）

C++、D：模板

使用泛型，可编写出不依赖于具体数据类型的程序，从而将算法从特定的数据结构中抽象出来。

实现时：算法和数据结构分离，减少重复的代码量。

使用时：算法和数据结构组合，适应不同的应用场景。

C++ 的STL（Standard Template Library） ，即标准模板库，是泛型程序设计最成功的应用案例。STL 是一个工业级的、高效的C++程序库。它包含了诸多在计算机科学领域里所常用的基本数据结构（如数组、向量、链表、队列、栈、树）和算法（如排序、查找）。这些数据结构和算法组合在一起，为我们的软件开发提供了良好的支持。

STL于1998年正式加入 C++ 标准。

Bjarne Stroustrup的《The C++ Programming Language》一书中，有1/3以上的篇幅讲述STL。

# 实验

***实验题目***

基于ACLLib库的精灵游戏

***ACLLib库***

https://github.com/wengkai/acllib

***示例代码***

clock、clocks、cube、snake、sprite

***实验要求***

实验分为4个难度级别，任意选择其中一个级别，按要求完成实验。

1. 封装（满分：60分）

阅读、理解示例代码，了解示例代码的功能，发现示例代码中存在的问题，独立编写自己的程序代码，实现示例代码的功能，避免示例代码中出现的问题。重写的代码要体现出封装的思想。

示例代码： sprite\encapsulation

2. 封装+继承（满分：70分）

阅读、理解示例代码，了解示例代码的功能，发现示例代码中存在的问题，独立编写自己的程序代码，实现示例代码的功能，避免示例代码中出现的问题。重写的代码要体现出封装和继承的思想。

示例代码： sprite\inheritance 

3. 封装+继承+多态（满分：80分）

阅读、理解示例代码，了解示例代码的功能，发现示例代码中存在的问题，独立编写自己的程序代码，实现示例代码的功能，避免示例代码中出现的问题。重写的代码要体现出封装、继承和多态的思想。

示例代码： sprite\polymorphism 

4. 封装+继承+多态+个性化（满分：100分）

在第3级的基础上，设计并实现更多的个性化功能，提高游戏的可玩性。

***实验评分***

提交内容：实验报告、程序代码

提交时间：第16周周日晚24:00前

提交方式：实验报告和全部程序代码一起打成一个zip包，文件名为：学号_姓名.zip（如：123456_张三.zip），用飞书客户端发送给助教。实验报告模板见《实验报告模板.docx》。程序代码包含全部源码文件和一个可执行文件。

评分标准：见《实验报告模板.docx》

***注意事项***

鼓励阅读、理解、学习、借鉴好的代码的思路和方法，但自己的实验代码要自己独立编写。禁止拷贝、粘贴别人的代码。如发现拷贝、粘贴别人的代码的现象，一律扣除相关部分的得分。




