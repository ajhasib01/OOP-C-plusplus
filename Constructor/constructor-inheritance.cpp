#include <iostream>
using namespace std;

// Base class
class Base {
private:
    double x, y; // attributes

public:
    // Constructor for Base class
    Base(double _x, double _y) : x(_x), y(_y) {}

    // Getter for x attribute
    double get_X() {
        return x;
    }

    // Getter for y attribute
    double get_Y() {
        return y;
    }

    // Setter for x attribute
    void set_X(double _x) {
        x = _x;
    }

    // Setter for y attribute
    void set_Y(double _y) {
        y = _y;
    }
};

// Derived class (inherits from Base class)
class ScndBase : public Base {
private:
    double z; // additional attribute specific to ScndBase

public:
    // Constructor for ScndBase class, initializes Base class attributes and z
    ScndBase(double _x, double _y, double _z) : Base(_x, _y), z(_z) {}

    // Setter for z attribute
    void set_Z(double _z) {
        z = _z;
    }

    // Getter for z attribute
    double get_Z() {
        return z;
    }
};

// Main function
int main() {
    // Creating an object of Base class with initial values
    Base b(2.2, 11);

    // Setting a new value for x using setter method and printing it using getter method
    b.set_X(2.7);
    cout << "X value of Base class: " << b.get_X() << endl;

    // Creating an object of ScndBase class with initial values
    ScndBase bb(2, 2, 2);

    // Printing the value of z using getter method
    cout << "Initial Z value of ScndBase class: " << bb.get_Z() << endl;

    // Setting a new value for z using setter method and printing it using getter method
    bb.set_Z(4);
    cout << "Updated Z value of ScndBase class: " << bb.get_Z() << endl;

    return 0;
}
