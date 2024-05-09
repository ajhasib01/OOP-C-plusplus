#include <iostream>
using namespace std;

// Base class
class Vehicle {
private:
    string name;
    int speed;
    string model;
public:
    // Function to set details of the vehicle
    void set_details() {
        cout << "Enter the type of vehicle: ";
        cin >> name;

        cout << "Enter the max speed: ";
        cin >> speed;

        cout << "Enter the model name: ";
        cin >> model;
    }

    // Function to print details of the vehicle
    void print_details() {
        cout << "Vehicle: " << name << endl;
        cout << "Max speed: " << speed << endl;
        cout << "Model: " << model << endl;
    }
};

// Intermediate class
class car {
private:
    int Budget;
public:
    // Function to set the budget
    void budget() {
        cout << "What's your budget: ";
        cin >> Budget;
    }

    // Function to display options based on the budget
    void options() {
        if (Budget > 1000) {
            cout << "You have 2 options." << endl;
        } else {
            cout << "You have no options." << endl;
        }
    }
};

// Derived class (grandchild of Vehicle)
class truck : public Vehicle, public car {
    // You can add additional members and functions specific to trucks here
    //Here you can  access both of the class Vehicle and car
};

int main() {
    char option;
    cout << "Choose vehicle type (C for car, T for truck): ";
    cin >> option;

    if (option == 'C' || option == 'c') {
        // Create an object of type truck
        truck t;

        // Set details, print details, set budget, and display options for the truck
        t.set_details();
        t.print_details();
        t.budget();
        t.options();
    } else if (option == 'T' || option == 't') {
        // Create an object of type truck
        truck t;

        // Set details, print details, set budget, and display options for the truck
        t.set_details();
        t.print_details();
        t.budget();
        t.options();
    } else {
        // Invalid option, prompt the user to choose again
        cout << "Invalid option. Please choose either 'C' or 'T'." << endl;
    }

    return 0;
}
