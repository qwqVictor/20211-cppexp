#include <iostream>
#include <iomanip>
#include <limits>
#include <cstring>
using namespace std;

#define echotype(type)     cout << #type": \t"<< (const char*)(strlen(#type) >= 6 ? "" : "\t") << " takes " << sizeof(type) << " byte" << (const char*)(sizeof(type) == 1 ? "" : "s") << "\t"; \ 
                            cout << "\t max value: " << +(numeric_limits<type>::max)(); \ 
                            cout << "\t min value: " << +(numeric_limits<type>::min)() << endl

void main_stage1() {
    cout << "type: \t\t" << "************size************" << endl;
    echotype(bool);
    echotype(char);
    echotype(signed char);
    echotype(unsigned char);
    echotype(short);
    echotype(int);
    echotype(unsigned);
    echotype(long);
    echotype(unsigned long);
    echotype(float);
    echotype(double);
    echotype(long long);
    echotype(long double);
}

void main_stage2() {
    unsigned short us = 65535;
    us = us + 1;
    cout << "unsigned short: \t";
    cout << setw(8) << hex << us << "," << setw(8) << dec << us << endl;
    signed short ss = 32767;
    ss = ss + 1;
    cout << "signed short: \t";
    cout << setw(8) << hex << us << "," << setw(8) << dec << ss << endl;
}

void main_stage3() {
    unsigned long ul = 65535;
    ul = ul + 1;
    cout << "unsigned long: \t";
    cout << setw(8) << hex << ul << "," << setw(8) << dec << ul << endl;
    signed long sl = 32767;
    sl = sl + 1;
    cout << "signed long: \t";
    cout << setw(8) << hex << sl << "," << setw(8) << dec << sl << endl;
}

int main(int argc, char const *argv[]) {
    cout << "Stu Name: Huang Kaisheng" << endl;
    cout << "Stu ID: 2020215138" << endl;

    cout << "\t\t\t\t[stage1] " << endl;
    main_stage1();

    cout << "\n\n\n\t\t[stage2] " << endl;
    main_stage2();

    cout << "\n\n\n\t\t[stage3] " << endl;
    main_stage3();
#ifdef WIN32
    system("pause");
#endif
    return 0;
}