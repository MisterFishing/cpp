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

***

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
    node<float> *ptr;
    node<float> node1,node2,node3;
    node1.set_value(97.5);
    node2.set_value(98.5);
    node3.set_value(99.5);
    node1.append(&node2);
	node2.append(&node3);

	for(ptr=&node1 ; ; ptr=ptr->get_next())
	{
		cout << ptr->get_value() << endl;
		if(ptr->get_next()==NULL) break;
	}
	
    return 0;
}

