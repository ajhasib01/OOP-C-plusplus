#include <iostream> 
#include <string>   

class HttpRequest // Define a Base class named HttpRequest
{
    unsigned char data[4]; // Define a private member variable array data to hold IP address components

public:
    HttpRequest(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
    {
        // Constructor for HttpRequest class, initializes the IP address components
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
    }

    unsigned char getData(int index) // Method to get IP address component at the specified index
    {
        return data[index];
    }

    virtual void log() {} // Virtual method to be overridden by derived classes, provides default implementation
};

