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
编译优化选项：-O

```
g++ -g -O test.cpp -o test.exe
```

用调试器检查是否内联成功。


