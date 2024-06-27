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
protected:
    string write_impl() const override {
        return "Writing sharply.";
    }

    string refill_impl() override {
        refill_characters();
        return "Refilling with ink.";
    }

};

class Pencil : public WritingAccessory {
public:
    Pencil(string name, string type, double price, int max_characters)
        : WritingAccessory(name, type, price, max_characters) {}

    string description() const override {
        return "Pencil (" + type + "). Name: " + name;
    }

protected:
    string write_impl() const override {
        return "Writing smoothly.";
    }

    string refill_impl() override {
        refill_characters();
        return "Refilling with lead.";
    }
};

class Marker : public WritingAccessory {
public:
    Marker(string name, string type, double price, int max_characters)
        : WritingAccessory(name, type, price, max_characters) {}

    string description() const override {
        return "Marker (" + type + "). Name: " + name;
    }

protected:
    string write_impl() const override {
        return "Writing boldly.";
    }

    string refill_impl() override {
        refill_characters();
        return "Refilling with marker ink.";
    }
};

class Highlighter : public WritingAccessory {
public:
    Highlighter(string name, string type, double price, int max_characters)
        : WritingAccessory(name, type, price, max_characters) {}

    string description() const override {
        return "Highlighter (" + type + "). Name: " + name;
    }

protected:
    string write_impl() const override {
        return "Highlighting brightly.";
    }

    string refill_impl() override {
        refill_characters();
        return "Refilling with highlighter ink.";
    }
};

class Document {
private:
    string text;
    unique_ptr<WritingAccessory> accessory;

public:
    Document(string _text, unique_ptr<WritingAccessory> _accessory)
        : text(_text), accessory(move(_accessory)) {}

    string write_document() {
        if (accessory->can_write(text.length())) {
            accessory->use_characters(text.length());
            return text + " " + accessory->write();
        } else {
            return "Not enough ink/lead to write the document.";
        }
    }

    string refill_accessory() const {
        return accessory->refill();
    }

};

void testPen() {
    try {
        Pen pen("Pilot", "Gel", 2.99, 100);
        assert(pen.description() == "Pen (Gel). Name: Pilot");
        assert(pen.write() == "Writing sharply.");
        assert(pen.refill() == "Refilling with ink.");
        assert(pen.get_price() == 2.99);
        assert(pen.get_type() == "Gel");
        cout << "Pen test passed!" << endl;
    } catch (const exception& e) {
        cout << "Pen test failed: " << e.what() << endl;
    }
}