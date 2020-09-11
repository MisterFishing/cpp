#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class animal 
{
	public:
	
	char name[8];

    animal(const char * my_name) 
	{
        strncpy(name, my_name, 7);
        name[7]='\0';
    }

    void speak() 
	{
        cout << name << ": HeHe... " << endl;
    }
};

class dog : public animal
{
	public:
    
	int birth;

    dog(const char * my_name, int my_birth):animal(my_name) 
	{
        birth=my_birth;
    }

    void speak() 
	{
        cout << name << ": Wang Wang... I born in " << birth << endl;
    }
};

class cat : public animal
{
	public:
    
	char color[8];

    cat(const char * my_name, const char * my_color):animal(my_name) 
	{
        strncpy(color, my_color, 7);
        color[7]='\0';
    }

    void speak() 
	{
        cout << name << ": Miao Miao... I am " << color << endl;
    }
};

int main()
{
    animal a("HeHe");
    dog b("WangCai", 2018);
    cat c("JiaFei", "BLACK");

    a.speak();
    b.speak();
    c.speak();

    return 0;
}

***

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class animal 
{
	public:
	
	char name[8];

    animal(const char * my_name) 
	{
        strncpy(name, my_name, 7);
        name[7]='\0';
    }

    void speak() 
	{
        cout << name << ": HeHe..." << endl;
    }
};

class dog : public animal
{
	public:
    
	int birth;

    dog(const char * my_name, int my_birth):animal(my_name) 
	{
        birth=my_birth;
    }

    void speak() 
	{
        cout << name << ": Wang Wang... I born in " << birth << endl;
    }
};

class cat : public animal
{
	public:
    
	char color[8];

    cat(const char * my_name, const char * my_color):animal(my_name) 
	{
        strncpy(color, my_color, 7);
        color[7]='\0';
    }

    void speak() 
	{
        cout << name << ": Miao Miao... I am " << color << endl;
    }
};

int main()
{
    animal a("HeHe");
    dog b("WangCai", 2018);
    cat c("JiaFei", "BLACK");

    a.speak();
    b.speak();
    c.speak();

	cout << endl << "----- We are in zoo -----" << endl << endl;
	
    animal *zoo[3]={&a, &b, &c};
    for(int i=0; i<3; i++)
	{
        zoo[i]->speak();
    }

    return 0;
}

***

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class animal 
{
	public:
	
	char name[8];

    animal(const char * my_name) 
	{
        strncpy(name, my_name, 7);
        name[7]='\0';
    }

    virtual void speak() 
	{
        cout << name << ": HeHe... " << endl;
    }
	
    virtual void eat() 
	{
        cout << name << ": Eating... " << endl;
    }
	
};

class dog : public animal
{
	public:
    
	int birth;

    dog(const char * my_name, int my_birth):animal(my_name) 
	{
        birth=my_birth;
    }

    void speak() 
	{
        cout << name << ": Wang Wang... I born in " << birth << endl;
    }
	
    void eat() 
	{
        cout << name << ": Wang Wang... I like bone " << endl;
    }
	
};

class cat : public animal
{
	public:
    
	char color[8];

    cat(const char * my_name, const char * my_color):animal(my_name) 
	{
        strncpy(color, my_color, 7);
        color[7]='\0';
    }

    void speak() 
	{
        cout << name << ": Miao Miao... I am " << color << endl;
    }
	
    void eat() 
	{
        cout << name << ": Miao Miao... I like fish " << endl;
    }

};

int main()
{
    animal a("HeHe");
    dog b("WangCai", 2018);
    cat c("JiaFei", "BLACK");

    a.speak();
    a.eat();

    b.speak();
    b.eat();

    c.speak();
    c.eat();

	cout << endl << "----- We are in zoo -----" << endl << endl;

    animal *zoo[3]={&a, &b, &c};
    for(int i=0; i<3; i++)
	{
        zoo[i]->speak();
        zoo[i]->eat();
    }

    return 0;
}

