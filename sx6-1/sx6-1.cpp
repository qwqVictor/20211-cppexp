#include <iostream>
using std::endl;
using std::cout;

struct Employee {
    long code;
    char name[20];
    float salary;
};
const int plen = 6;
Employee person[plen] = {
    { 1, "jone", 339.0 },
    { 2, "david", 449.0 },
    { 3, "marit", 311.0 },
    { 4, "jasen", 623.0 },
    { 5, "peter", 400.0 },
    { 6, "yoke", 511.0 }
};
void printEmployee(const Employee p);

int main(int argc, char const *argv[]) {
    Employee temp, *p;
    for (int i = 1; i < plen; i++) {
        for (p = person; p <= person + plen - 1 - i; p++) {
            if (p->salary > (p+1)->salary) {
                temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
        }
    }
    for (int k = 0; k < plen; k++)
        printEmployee(person[k]);
    
#ifdef WIN32
    system("pause");
#endif
    return 0;
}

void printEmployee(const Employee p) {
    cout << p.name << "\t" << p.code << "\t" << p.salary << endl;
}