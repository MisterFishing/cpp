#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char buffer[100];
    char buffer_2[100];

    printf("input_1: ");
    scanf("%s",&buffer);
    printf("output_1: %s\n", buffer);

    operator<<(cout,"input_2: ");
    operator>>(cin,buffer);
    operator<<(cout,"output_2: ");
    operator<<(cout,buffer);
    operator<<(cout,"\n");

    cout << "input_3: ";
    cin >> buffer;
    cout << "output_3: ";
    cout << buffer;
    cout << "\n";

    cout << "input_4: ";
    cin >> buffer;
    cout << "output_4: " << buffer << "\n";

    cout << "input_5: ";
    cin >> buffer;
    cout << "output_5: " << buffer << endl;

    cout << "input_6 input_7: ";
    cin >> buffer >> buffer_2;
    cout << "output_6: " << buffer << endl << "output_7: " << buffer_2 << endl;

    return 0;
}

