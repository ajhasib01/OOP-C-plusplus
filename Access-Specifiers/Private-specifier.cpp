#include <iostream>
using namespace std;

class Animal{  // The Class
    private:         //Access Specifier (Private - No one can Access)
        int weight_of_Animal; //Attribute {int variable}  
        
public:    
    string Animal_name;    //Attribute {String variable}


};

int main(){

Animal myObj; // Create an object of Animal
 
// Access Attribute and set values.
myObj.weight_of_Animal = 120; //Not allowed (Because it's private- inaccessible)
myObj.Animal_name= "Lion"; ////Allowed (Because it's public- Accessible)

//Print attribute values
cout<<myObj.weight_of_Animal<<"kg"<<endl;
cout<<myObj.Animal_name<<endl;

}