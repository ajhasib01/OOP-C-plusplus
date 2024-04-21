#include <iostream>
using namespace std;

class Animal{  // The Class
    public:         //Access Specifier
        void Inside_Method(int num); //Method or Function Declaration

};

void Animal::Inside_Method(int num){ //Methode outside of the class

    cout<<num<<"Animal(s)"<<endl;


}

int main(){
    Animal myObj1;// create an object of Animal base class.
    myObj1.Inside_Method(10); // Calling Inside method.

}