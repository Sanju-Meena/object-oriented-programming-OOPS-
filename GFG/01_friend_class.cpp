#include <iostream>
using namespace std;
/*
All-access pass: A friend class gets full access to all private and protected variables and functions.
Not transferable: If A is a friend of B, and B is a friend of C, A is not a friend of C.
Not inherited: A friend class's child class does not automatically get friendship.*/

class Engine {
private:
    int horsepower;
    
    // A private member function
    void ignite() {
        cout << "Engine ignition sequence started internally.\n";
        cout<<"mycarengine horsepower is "<<horsepower<<endl;
    }

    public:
    void ignition() {
        cout<<"mycarengine horsepower is "<<horsepower<<endl;
    }

public:
    Engine(int hp) : horsepower(hp) {}

    // Granting friendship to the Mechanic class
    friend class Mechanic;
};

class Mechanic {
public:
    void tuneEngine(Engine &e) {

        cout << "Original Horsepower: " << e.horsepower << "\n";
        e.horsepower += 100;
        cout << "Upgraded Horsepower: " << e.horsepower << "\n";
        e.ignite();
    }
};

int main() {
    Engine mycarengine(300);
    Mechanic proMechanic;
    
    
    proMechanic.tuneEngine(mycarengine);
    mycarengine.ignition();
    return 0;
}