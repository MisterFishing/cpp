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
        my_name();
        cout << endl;
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
        my_name();
        my_birth();
        cout << endl;
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
        my_name();
        my_color();
        cout << endl;
    }

    void my_color() 
    {
        cout << "I am " << color << endl;
    }
};

int main()
{
    animal a("Animal");
    dog b("WangCai", 2021);
    cat c("JiaFei", "BLACK");
    
    cout << "--- At home ---" << endl;
    a.say_hello();
    b.say_hello();
    c.say_hello();
    
    return 0;
}