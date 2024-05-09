#include <iostream>
using namespace std;

class Vehicle {
private:
    string name;
    int speed;
    string model;
public:
    void set_details(); // Declaration of member function set_details

    void print_details(); // Declaration of member function print_details
};

// Definition of member function set_details
void Vehicle::set_details() {
    cout << "Enter the type of vehicle: ";
    cin >> name;

    cout << "Enter the max speed: ";
    cin >> speed;

    cout << "Enter the model name: ";
    cin >> model;
}

// Definition of member function print_details
void Vehicle::print_details() {
    cout << "Vehicle: " << name << endl;
    cout << "Max speed: " << speed << endl;
    cout << "Model: " << model << endl;
}

int main() {
    // Create an object of the Vehicle class
    Vehicle car;

    // Call member function to set details
    car.set_details();

    // Call member function to print details
    car.print_details();

    return 0;
}
