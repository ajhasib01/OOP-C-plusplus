#include <iostream>
using namespace std;

class Animal{  // The Class
    public:         //Access Specifier
        int weight; //Attribute {int variable}  
        string animal_name;    //Attribute {String variable}


};

int main(){

Animal myObj1; // Create an object1 of Animal
 
// Access Attribute and set values.
myObj1.weight = 100;
myObj1.animal_name = "Lion";

//Print attribute values
cout<<myObj1.weight<<"kg"<<endl;
cout<<myObj1.animal_name<<endl;

Animal myObj2; //Create an object2 of Animal
myObj2.weight = 5;
myObj2.animal_name ="Parrot"

cout<<myObj2.weight<<"kg"<<endl;
cout<<myObj2.animal_name<<endl;

}