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