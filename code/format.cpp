#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float pi=3.1415926;
	cout << pi << endl;
	cout.setf(ios::fixed);
    cout << setprecision(0) << pi << endl;
    cout << setprecision(1) << pi << endl;
    cout << setprecision(2) << pi << endl;
    cout << setprecision(3) << pi << endl;	
	cout.setf(ios::scientific, ios::floatfield);
    cout << setprecision(0) << pi << endl;
    cout << setprecision(1) << pi << endl;
    cout << setprecision(2) << pi << endl;
    cout << setprecision(3) << pi << endl;	
	cout << true << endl;
	cout << false << endl;
	cout << ((true)?"true":"false") << endl;
	cout << ((false)?"true":"false") << endl;
	cout.setf(ios::boolalpha);	
	cout << true << endl;
	cout << false << endl;
	cout << pi << endl;
    return 0;
}
