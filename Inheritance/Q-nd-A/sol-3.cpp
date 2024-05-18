#include <iostream> 
#include <string>   

class HttpRequest // Define a Base class named HttpRequest
{

public:


    virtual void log() // Define a virtual function log which will be overridden by derived classes
    {

    }

};

class GetRequest:public HttpRequest // Define a class named GetRequest which inherits from HttpRequest
{
    std::string url; // Define a private member variable named url of type string

public:
    GetRequest(std::string _url) // Constructor for GetRequest taking a string argument
        : url(_url) // Initialize the url member variable with the provided value
    {}

    void log() override // Override the log method from the base class
    {
        std::cout << "Http GET Request of from a.b.c.d to " << url << std::endl; // Print a message indicating an HTTP GET request
    }


};