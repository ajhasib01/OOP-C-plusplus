#include <iostream>
using namespace std;

class Animal{  // The Class

    public:         //Access Specifier
        string Name; //Attribute (String)
        int Number; //Attribute (int)

        Animal(string name, int number){//create a constructor name Animal and add parameters.
            Name = name ;
            Number = number;
       }
};

int main(){

    Animal myObj("Dogs",10); //Create an object of Class Animal and call the constructor with different values.
    cout<<"There are "<<myObj.Number<<" "<<myObj.Name<<endl;

    return 0;

}
