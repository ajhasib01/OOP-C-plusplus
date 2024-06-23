#include <iostream>
#include <string>
#include <vector>
using namespace std;

using str = std::string;

class WritingAccessory{

private:
    str name;
    str type;
    double price;
    
    virtual str Write() const = 0;

public:
    WritingAccessory(str _name, str _type, double _price):name(_name),type(_type),price(_price){}

    virtual str Description() const = 0;
    virtual str get_type() const{

        return type;
    }

    virtual double get_price() const{
        return price;
    }

    virtual ~WritingAccessory() = default;
};
