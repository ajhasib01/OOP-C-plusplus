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

void testPencil() {
    try {
        Pencil pencil("Staedtler", "HB", 0.99, 200);
        assert(pencil.description() == "Pencil (HB). Name: Staedtler");
        assert(pencil.write() == "Writing smoothly.");
        assert(pencil.refill() == "Refilling with lead.");
        assert(pencil.get_price() == 0.99);
        assert(pencil.get_type() == "HB");
        cout << "Pencil test passed!" << endl;
    } catch (const exception& e) {
        cout << "Pencil test failed: " << e.what() << endl;
    }
}

void testMarker() {
    try {
        Marker marker("Sharpie", "Permanent", 1.99, 50);
        assert(marker.description() == "Marker (Permanent). Name: Sharpie");
        assert(marker.write() == "Writing boldly.");
        assert(marker.refill() == "Refilling with marker ink.");
        assert(marker.get_price() == 1.99);
        assert(marker.get_type() == "Permanent");
        cout << "Marker test passed!" << endl;
    } catch (const exception& e) {
        cout << "Marker test failed: " << e.what() << endl;
    }
}

void testHighlighter() {
    try {
        Highlighter highlighter("Stabilo", "Chisel Tip", 1.49, 80);
        assert(highlighter.description() == "Highlighter (Chisel Tip). Name: Stabilo");
        assert(highlighter.write() == "Highlighting brightly.");
        assert(highlighter.refill() == "Refilling with highlighter ink.");
        assert(highlighter.get_price() == 1.49);
        assert(highlighter.get_type() == "Chisel Tip");
        cout << "Highlighter test passed!" << endl;
    } catch (const exception& e) {
        cout << "Highlighter test failed: " << e.what() << endl;
    }
}

void testDocumentWithPen() {
    try {
        auto pen = make_unique<Pen>("Pilot", "Gel", 2.99, 100);
        Document doc("Hello, world!", move(pen));
        assert(doc.write_document() == "Hello, world! Writing sharply.");
        assert(doc.refill_accessory() == "Refilling with ink.");
        cout << "Document with Pen test passed!" << endl;
    } catch (const exception& e) {
        cout << "Document with Pen test failed: " << e.what() << endl;
    }
}

void testDocumentWithPencil() {
    try {
        auto pencil = make_unique<Pencil>("Staedtler", "HB", 0.99, 200);
        Document doc("Drawing a BMW", move(pencil));
        assert(doc.write_document() == "Drawing a BMW Writing smoothly.");
        assert(doc.refill_accessory() == "Refilling with lead.");
        cout << "Document with Pencil test passed!" << endl;
    } catch (const exception& e) {
        cout << "Document with Pencil test failed: " << e.what() << endl;
    }
}

void testDocumentWithMarker() {
    try {
        auto marker = make_unique<Marker>("Sharpie", "Permanent", 1.99, 50);
        Document doc("Marking important points.", move(marker));
        assert(doc.write_document() == "Marking important points. Writing boldly.");
        assert(doc.refill_accessory() == "Refilling with marker ink.");
        cout << "Document with Marker test passed!" << endl;
    } catch (const exception& e) {
        cout << "Document with Marker test failed: " << e.what() << endl;
    }
}

int main(){

testPen();

testDocumentWithPen();

}