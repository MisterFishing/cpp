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
int main(){
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
int main(){
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
int main(){
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

int f(){
    x=2;
    return x;
}

int main(){
    int a=3;
    a = f();
    cout << a << endl;
}
```

右值只能放在赋值符号的右边，因为它代表的，仅仅是一个“值”。

#### 返回引用——左值。

```
int x=1;

int & f(){
    x=2;
    return x;
}

int main(){
    int a=3;
    f() = a;
    cout << x << endl;
}
```

左值既可以放在赋值符号的左边，也可以放在赋值符号的右边，因为它代表的是一个“内存单元”。

# C++语言中的内联函数

## 内联函数例子

```
inline int add(int value) {
    int x;
    x = value + 1;
    x = x + 2;
    x = x + 3;
    return x;
}

int main(){
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

## struct vs class

1. 组合

C的struct只能把变量组合起来，每一个变量称为一个“字段”。

C++的class可以把变量和函数组合起来，每一个变量或函数都称为“类成员”，其中，变量也称为“成员变量”，函数也称为“成员函数”。

2. 隐藏

C的struct不具备隐藏的功能，使用者可以访问所有“字段”。

C++的class具备隐藏功能，可以把需要公开的“类成员”放到public区，供使用者使用；把需要隐藏的“类成员”放到private区，对使用者透明。

为了提供兼容性，C++也支持struct，但它的功能在原先struct的基础上有所扩展，更加接近于class。

【C++中struct与class的区别与比较】

https://blog.csdn.net/weixin_39640298/article/details/84349171

3. 实例

struct和class都是特殊的数据类型，和普通的数据类型（如：int、float、……）一样，struct和class都可以用来定义变量。使用一个数据类型来定义变量，称为对该数据类型的实例化。定义出来的每一个变量，都称为该数据类型的一个实例（instance ）。

```
int a,b,c;
struct student zs,ls,ww;
```

我们用一个特殊的术语来称呼class的实例，这个术语就是——object（对象）。

```
class student { ... }
student zs,ls,ww;
```

客观世界中存在很多不同类型的实体。同一种类型的实体，具备相同的特征，这些特征，对应一个class（类）；符合同一种类型特征的实体有若干个，每一个实体对应一个object（对象）。

所以，类和对象是对客观世界的类型和实体的抽象描述，使用面向对象的方法，可以设计出更加接近于客观世界的程序代码。

