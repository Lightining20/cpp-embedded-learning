#include <iostream>
using namespace std;

class Sensor
{
private:
    int *value;

public:
    // Constructor
    Sensor(int v)
    {
        value = new int(v);
        cout << "Sensor created\n";
    }

    // Copy Constructor (Deep Copy)
    Sensor(const Sensor &other)
    {
        value = new int(*other.value);
        cout << "Copy constructor called\n";
    }

    // Destructor
    ~Sensor()
    {
        delete value;
        cout << "Sensor destroyed\n";
    }

    void display()
    {
        cout << "Value: " << *value << endl;
    }
};

int main()
{
    Sensor s1(10);  // normal object
    Sensor s2 = s1; // copy constructor called

    s1.display();
    s2.display();

    return 0;
}
