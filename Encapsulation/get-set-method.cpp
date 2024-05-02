#include <iostream>
using namespace std;

class Animal{  // The Class
    private:         //Access Specifier 
        string animal_name;    //Attribute {String variable}


    public:         //Access Specifier

        void set_name(string name){  //setter : It will set the name which you wanted to set.
            animal_name = name;
        }

        string get_name(){   //getter : It will get the name or print the name.
            return animal_name;
        }        

};


int main(){

Animal a; //here "a" is an object of Animal

a.set_name("Monkey"); //Name set as Monkey

cout<<a.get_name()<<endl; //This will print out or get the name.

}