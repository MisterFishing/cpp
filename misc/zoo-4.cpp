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

    virtual void my_food() = 0;

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

    void my_food() 
    {
        cout << "I like bone" << endl << endl;
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

    void my_food() 
    {
        cout << "I like fish" << endl << endl;
    }
};

int main()
{
    dog b1("Dog1", 2021);
    dog b2("Dog2", 2022);
    cat c1("Cat1", "BLACK");
    cat c2("Cat2", "WHITE");

    cout << "--- At zoo ---" << endl;

    animal *zoo[4]={&b1, &b2, &c1, &c2};
    for(int i=0; i<4; i++)
    {
        zoo[i]->say_hello();
    }
        
    return 0;
}