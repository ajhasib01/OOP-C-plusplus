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

public:
    WritingAccessory(string _name, string _type, double _price, int _max_characters)
        : name(_name), type(_type), price(_price), max_characters(_max_characters), current_characters(_max_characters) {}

    virtual string description() const = 0;
    virtual double get_price() const {
        return price;
    }
    virtual string get_type() const {
        return type;
    }

    bool can_write(int characters) const {
        return current_characters >= characters;
    }

    void use_characters(int characters) {
        if (characters <= current_characters) {
            current_characters -= characters;
        } else {
            throw runtime_error("Not enough ink/lead to write.");
        }
    }

    void refill_characters() {
        current_characters = max_characters;
    }
    
    virtual ~WritingAccessory() = default;

    string write() const {
        return write_impl();
    }

    string refill() {
        return refill_impl();
    }

};

class Pen : public WritingAccessory {
public:
    Pen(string name, string type, double price, int max_characters)
        : WritingAccessory(name, type, price, max_characters) {}

    string description() const override {
        return "Pen (" + type + "). Name: " + name;
    }

};