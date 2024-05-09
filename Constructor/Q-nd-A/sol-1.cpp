#include <iostream>

// Class to represent an IPv4 address
class Ipv4Address {
    unsigned char data[4]; // Array to store the four octets of the IPv4 address

public:
    // Getter method to retrieve the value of a specific octet at the given index
    unsigned char getData(int index) {
        return data[index];
    }

    // Setter method to set the value of a specific octet at the given index
    void setData(int index, unsigned char value) {
        data[index] = value;
    }
};

// Class to represent a request with an origin IPv4 address
class Request {
    Ipv4Address origin; // Origin of the request

public:
    // Constructor to initialize the origin field with provided IPv4 address octets
    Request(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {
        origin.setData(0, a); // Set the first octet
        origin.setData(1, b); // Set the second octet
        origin.setData(2, c); // Set the third octet
        origin.setData(3, d); // Set the fourth octet
    }

    // Getter method to retrieve the origin IPv4 address
    Ipv4Address getOrigin() {
        return origin;
    }

    // Method to log the request details, printing the origin IPv4 address
    void log() {
        std::cout << "Request of unknown type from: "
                  << static_cast<int>(origin.getData(0)) << "." // First octet
                  << static_cast<int>(origin.getData(1)) << "." // Second octet
                  << static_cast<int>(origin.getData(2)) << "." // Third octet
                  << static_cast<int>(origin.getData(3)) << std::endl; // Fourth octet
    }
};

// Main function to demonstrate the classes
int main() {
    // Create a request object with the origin IPv4 address 192.168.0.2
    Request req(192, 168, 0, 2);

    // Retrieve the origin IPv4 address and log the request
    Ipv4Address origin = req.getOrigin(); //The getOrigin() method returns a copy of the Ipv4Address object representing the origin, without directly interacting with the internal data of the Request object.
    
    req.log(); //And log directly copy from getOrigin without interacting internal data 

    // These are exmmple of Encapsulation and Abstraction. Also provides  consistent interface.

    return 0;
}
