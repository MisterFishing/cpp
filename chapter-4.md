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
