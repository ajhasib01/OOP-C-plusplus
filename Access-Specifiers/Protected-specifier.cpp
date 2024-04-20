#include <iostream>
using namespace std;

class Animal{  // Base Class
    protected:         //Access Specifier (Protected - No one can Access)
        int Num_of_Animal; //Attribute {int variable}  
       
//Protected access modifier is similar to that of private access modifiers.
//You can also use it Like private access specifier
//Use similar code from private and check it just make sure to create a public specifier first.

};

//Create a Sub class name mammals
class mammals:public Animal{

    public:
        void setNum(int Num){
            // Child or Sub class is able to access the inherited 
        
           Num_of_Animal = Num;

           // protected data members of base class
        }
 void displayNum() 
    { 
        cout << "Num_OF_Animal from from protected Access Specifier is: " << Num_of_Animal << endl; 
    } 
};

int main() 
{ 
  
    mammals obj; //Create an Object from mammal's class
  
    // member function of the sub class can 
    // access the protected data members of the base class 
  
    obj.setNum(11); 
    obj.displayNum(); 
    return 0; 
} 