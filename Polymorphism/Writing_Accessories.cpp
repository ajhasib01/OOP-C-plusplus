#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cassert>
using namespace std;

class WritingAccessory{

protected:
    string name;
    string type;
    double price;
    int max_characters;
    int current_characters;

    virtual string write_impl() const = 0; 
    virtual string refill_impl() = 0;








};
