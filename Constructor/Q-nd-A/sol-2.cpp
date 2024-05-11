#include <iostream>
#include <string>

//Base class

class Request{ //In the question it's says a class HttpRequest which extends Request.
                //Here extends mean Request is the base class and HttpRequest will be the sub-class.
public:
    virtual void log(){
        std::cout<<"Request for loging"<<std::endl;
    }

};

class HttpsRequest:public Request{

    


};