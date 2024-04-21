#include <iostream>
using namespace std;

class Animal{  // The Class
    public:         //Access Specifier
       
       Animal(){ //create a constructor name Animal.
        cout<<"TIGER"<<endl;
       }
};

int main(){

    Animal myObj; //Create an object of Class Animal.
    return 0;

}