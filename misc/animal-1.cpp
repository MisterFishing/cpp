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