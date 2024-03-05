#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

typedef struct people{
    char* name;
    int age;
    char sex;
} people;

int main() {
    people p1, p2, p3;

    p1.name = "Eduardo";
    p2.name = "Saulo";
    p3.name = "Gabriel Matos";

    p1.age = 20;
    p2.age = 19;
    p3.age = 19;

    p1.sex = 'M';
    p2.sex = 'M';
    p3.sex = 'M';

    cout << p1.name << " is " << p1.age << " years old." << endl;
    cout << p2.name << " is " << p2.age << " years old." << endl;
    cout << p3.name << " is " << p3.age << " years old." << endl;
}