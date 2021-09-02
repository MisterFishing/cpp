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

```
    shenshou s("ShenShou", 2022, "GOLD");
    cout << s.name << endl;
    s.my_name();
    s.animal::say_hello();
```