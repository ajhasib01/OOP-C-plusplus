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

class HttpsRequest:public Request{
    std::string url;
public:
    HttpsRequest(std::string _url,std::string _user):Request(_user),url(_url){}

    std::string get_url(){
        return url;
    }

    void set_url(std::string _url){

        url = _url;
    }

    void log()override{
        std::cout<<"Https Request of from "<<user << " to "<< url <<std::endl;
    }

};