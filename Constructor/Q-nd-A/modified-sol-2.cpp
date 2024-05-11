#include <iostream>
#include <string>

//Base class

class Request{ 
    
protected:
        std::string user;
public:
    Request(std::string _user):user(_user){}

    std::string get_user(){
        return user;
    }

    virtual void log(){
        std::cout<<"Request for logging"<<std::endl;
    }

};