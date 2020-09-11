#include <iostream>
using namespace std;

int GetMax2(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int GetMax3(int x, int y, int iz)
{
    int tmp1,tmp2;
    tmp1=GetMax2(x,y);
    tmp2=GetMax2(tmp1,iz);
    return tmp2;
}


int main()
{
    int a,b,c;
    int number;
    int max;

    cout << "Input number: ";
    cin >> number;

    if(number==2)
    {
        cout << "Input a b: ";
        cin >> a >> b;
        max=GetMax2(a, b);
        cout << "max: " << max << endl;
    }

    if(number==3)
    {
        cout << "Input a b c: ";
        cin >> a >> b >> c;
        max=GetMax3(a, b, c);
        cout << "max: " << max << endl;
    }

    return 0;
}

***

#include <iostream>
using namespace std;

int GetMax(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int GetMax(int x, int y, int z)
{
    int tmp1,tmp2;
    tmp1=GetMax(x,y);
    tmp2=GetMax(tmp1,z);
    return tmp2;
}


int main()
{
    int a,b,c;
    int number;
    int max;

    cout << "input number: ";
    cin >> number;

    if(number==2)
    {
        cout << "input a b: ";
        cin >> a >> b;
        max=GetMax(a, b);
        cout << "max: " << max << endl;
    }

    if(number==3)
    {
        cout << "input a b c: ";
        cin >> a >> b >> c;
        max=GetMax(a, b, c);
        cout << "max: " << max << endl;
    }

    return 0;
}

***

#include <iostream>
using namespace std;

int GetMax(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

double GetMax(double dx, double dy)
{
    if(dx>dy)
        return dy;
    else
        return dy;
}

int main()
{
    int a,b;
    double da,db;

    cout << "Input a b: ";
    cin >> a >> b;
    cout << "Max: " << GetMax(a, b) << endl;

    cout << "Input da db: ";
    cin >> da >> db;
    cout << "Max: " << GetMax(da, db) << endl;

    return 0;
}

