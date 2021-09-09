#include <iostream>
using namespace std;

#define PI 3.14

int main()
{
    float x, y;
    const float pi=3.14;

    x=PI;
    y=pi;
    cout << "x: " << x << endl << "y: " << y << endl;


	float * const p1=&x;
//	p1=&y;
//	*p1=1.11;

	float const * p2=&x;
//	p2=&y;
//	*p2=1.11;

	float const * const p3=&x;
//	p3=&y;
//	*p3=1.11;

    cout << "x: " << x << endl << "y: " << y << endl;

    return 0;
}

