#include <iostream>
using namespace std;

class Animal{  // The Class
    public:         //Access Specifier
        int Num_of_Animal; //Attribute {int variable}  
        string animal_name;    //Attribute {String variable}


};

int main(){

Animal myObj; // Create an object of Animal
 
// Access Attribute and set values.
myobj.Num_of_Animal = 10;
myobj.animal_name = "Lion";

//Print attribute values
cout<<myObj.Num_of_Animal<<endl;
cout<<myObj.animal_name<<endl;

}