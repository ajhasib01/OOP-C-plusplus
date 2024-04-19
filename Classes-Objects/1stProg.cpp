#include <iostream>
using namespace std;

class employee
{
    string name;
    int age;
    int salary;

public:
    employee(const string &name, int age, int salary) : name(name), age(age), salary(salary) {}

    const string &getName()
    {
        return name;
    }

    int getAge()
    {

        return age;
    }

    int getSalary()
    {
        return salary;
    }

    void setName(const string &Newname)
    {
        if (Newname.length() <= 10)
        {
            name = Newname;
            cout << "New name is" << name << endl;
        }
        else
            cout << "Sorry no words more than 10" << endl;
    }
};

int main()
{

    employee em("Hasib", 22, 3000);

    cout << em.getAge() << endl;

    em.setName("Arshad");
}
