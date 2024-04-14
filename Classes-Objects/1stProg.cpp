#include <iostream>
using namespace std;

class employee{
    string name;
    int age;
    int salary;
public:
    employee(string name, int age, int salary):name(name),age(age),salary(salary){}

    string getName(){
        return name;
    }

    int getAge(){

        return age;
    }

    int getSalary(){
        return salary;
    }

};




int main(){

employee em("Hasib",22,3000);

cout<<em.getAge()<<endl;


}
