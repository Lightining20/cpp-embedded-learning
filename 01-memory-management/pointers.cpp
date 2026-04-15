#include <iostream>
using namespace std;

int main()
{
    int var = 10;
    int *p;
    cout << "p: " << p << endl;
    cout << "var: " << var << endl;
    cout << "&var: " << &var << endl;

    cout << "After assigning the address of var to p: " << endl;
    p = &var;
    cout << "p: " << p << endl;
    cout << "var: " << var << endl;
    cout << "&var: " << &var << endl;

    cout << "After updating the value pointed to by p: " << endl;
    *p = 15;
    cout << "var: " << var << endl;
    cout << "p: " << *p << endl;

    cout << "After updating the value of var directly: " << endl;
    var = 20;
    cout << "var: " << var << endl;
    cout << "p: " << *p << endl;
}
