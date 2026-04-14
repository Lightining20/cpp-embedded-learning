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

    // Copy Constructor
    Sensor(const Sensor &other)
    {
        value = new int(*other.value);
        cout << "Copy constructor called\n";
    }

    // Copy Assignment Operator
    Sensor &operator=(const Sensor &other)
    {
        if (this == &other)
            return *this; // self-assignment

        delete value;                  // free old memory
        value = new int(*other.value); // deep copy

        cout << "Copy assignment called\n";
        return *this;
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
    Sensor s1(10);  // constructor
    Sensor s2 = s1; // copy constructor

    Sensor s3(5); // constructor
    s3 = s1;      // copy assignment

    s1.display();
    s2.display();
    s3.display();

    return 0;
}
