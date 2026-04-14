#include <iostream>

class Sensor
{
private:
    int *value;

public:
    Sensor(int v)
    {
        value = new int(v);
        std::cout << "Sensor created\n";
    }

    ~Sensor()
    {
        delete value;
        std::cout << "Sensor destroyed\n";
    }

    void display()
    {
        std::cout << "Value: " << *value << std::endl;
    }
};

int main()
{
    Sensor s1(10);
    s1.display();
    return 0;
}