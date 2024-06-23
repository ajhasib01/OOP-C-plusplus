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






};
