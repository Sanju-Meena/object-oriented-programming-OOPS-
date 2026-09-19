/*
Q1. What are the different data types present in C++?
    The 4 data types in C++ are given below:

    Primitive Datatype(basic datatype). Example- char, short, int, float, long, double, bool, etc.
    Derived datatype. Example- array, pointer, etc.
    Enumeration. Example- enum
    User-defined data types. Example- structure, class, etc

Q2. What are the static members and static member functions?
    // Normally, when you create objects from a class, every object gets its own separate copies of variables and functions. But when you tag something as static, 
       it stops belonging to individuals and becomes community property.
    // When a variable in a class is declared static, space for it is allocated for the lifetime of the program. No matter how many objects of that class have
       been created, there is only one copy of the static member. So same static member can be accessed by all the objects of that class.

    // A static member function can be called even if no objects of the class exist and the static function are accessed using only the class name and 
       the scope resolution operator ::
*/

#include <bits/stdc++.h>
using namespace std;

class Car {
private:
    string licensePlate;
    static int totalCarsParked; // Static variable

public:
    Car(string plate) {
        licensePlate = plate;
        totalCarsParked++;
    }

    // Static member function
    static int getTotalCars() {return totalCarsParked; }

    void showInfo() {
        // Method 2: Direct access inside another member function (no :: or object needed)
        cout << "Car plate: " << licensePlate << " | Total cars via direct access: " << totalCarsParked << endl;
    }
};

// must Initialize static variable outside the class 
int Car::totalCarsParked = 0;

int main() {
    Car c1("ABC-1234");
    Car c2("XYZ-5678");

    // Method 1: Accessing the static function using an object instance and the dot operator (.)
    // Note: This works, but using ClassName::getTotalCars() is preferred practice.
    cout << "Count accessed using object c1: " << c1.getTotalCars() << endl;

    // Demonstrating Method 2 (Direct access inside a member function)
    c1.showInfo();

    return 0;
}