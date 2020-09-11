#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
const int num=1000000;

class CString{
    char buf[num];

public:
    CString(){
        memset(buf, 0, num);
    }

    ~CString(){
    }

    void change(char const *str){
        strcpy(buf,str);
    }

    char *get(){
        return buf;
    }
};


int main()
{
    for(int i=1; i<=3000; i++){
        CString *abc=new CString;
        abc->change("abc");
        cout << i << ":" << abc->get() << endl;
		delete abc;
    }

    return 0;
}

***

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
const int num=1000000;

class CString{
    char *buf;

public:
    CString(){
        buf=new char[num];
        memset(buf, 0, num);
    }

    ~CString(){
        delete []buf;
    }

    void change(char const *str){
        strcpy(buf,str);
    }

    char *get(){
        return buf;
    }
};


int main()
{
    for(int i=1; i<=3000; i++){
        CString *abc=new CString;
        abc->change("abc");
        cout << i << ":" << abc->get() << endl;
		delete abc;
    }

    return 0;
}

***

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
const int num=1000000;

class CString{
    char *buf;

public:
    CString(){
        buf=new char[num];
        memset(buf, 0, num);
    }

    ~CString(){
        delete []buf;
    }

    void change(char const *str){
        strcpy(buf,str);
    }

    char *get(){
        return buf;
    }
};


int main()
{
    CString abc;
    abc.change("abc");
    cout << abc.get() << endl;

    CString def=abc;
    cout << def.get() << endl;

    return 0;
}

***

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
const int num=1000000;

class CString{
    char *buf;

public:
    CString(){
        buf=new char[num];
        memset(buf, 0, num);
    }

    CString(CString &old){
        buf=new char[num];
        strcpy(buf,old.buf);
    }

    ~CString(){
		cout << "delete" << endl;
        delete []buf;
    }

    void change(char const *str){
        strcpy(buf,str);
    }

    char *get(){
        return buf;
    }
};


int main()
{
    CString abc;
    abc.change("abc");
    cout << abc.get() << endl;

    CString def=abc;
    cout << def.get() << endl;

    return 0;
}

