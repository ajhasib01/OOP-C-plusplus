#include <iostream>
using namespace std;

class Employee{
    string name;
    int age;
    int salary;


public:
    Employee(string name, int age, int salary):(name(name),age(age),salary(salary){
    

    }


    string getName(){
        return name;
    }

    int getAge(){

        return age;
    }  

    int getsalary(){
        return salary;
    }
};

int main(){

Employee em("Hasib",22,3333);



cout<<em.getAge()<<endl;


}


