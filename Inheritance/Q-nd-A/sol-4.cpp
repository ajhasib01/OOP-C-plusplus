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


class GetRequest: public HttpRequest // Define a sub-class named GetRequest which inherits from HttpRequest
{
    std::string url; // Define a private member variable url to hold the URL

public:
    GetRequest(unsigned char a, unsigned char b, unsigned char c, unsigned char d, std::string url)
        : HttpRequest(a, b, c, d), url(url) // Constructor for GetRequest, initializes IP address components and url
    {}

    void log() override // Override the log method from the base class
    {
        // Print an HTTP GET request message including the IP address components and the URL
        std::cout << "Http GET Request from "
                  << static_cast<int>(getData(0)) << "."
                  << static_cast<int>(getData(1)) << "."
                  << static_cast<int>(getData(2)) << "."
                  << static_cast<int>(getData(3))
                  << " to " << url << std::endl;
    }
};
