#include <iostream>
using std::cout;
using std::endl;

/* 不使用 using namespace std; 的情况下，swap 不会调用库函数 */
void swap(int *p1, int *p2);

int main(int argc, char const *argv[]) {
    cout << "-----------------------------------------" << endl;
    int iv1 = 888;
    int *pointer_1 = &iv1;                              // 指向 iv1 变量所在的内存地址
    cout << "iv1\t\t = " << iv1 << endl;                // 888
    cout << "*pointer_1\t = " << *pointer_1 << endl;    // 888
    cout << "&iv1\t\t = " << &iv1 << endl;              // 输出 iv1 变量的地址
    cout << "pointer_1\t = " << pointer_1 << endl;      // 输出同上

    cout << "-----------------------------------------" << endl;
    int iv2 = 666;
    int *pointer_2 = &iv2;
    cout << "iv2\t\t = " << iv2 << endl;
    cout << "*pointer_2\t = " << *pointer_2 << endl;
    cout << "&iv2\t\t = " << &iv2 << endl;
    cout << "pointer_2\t = " << pointer_2 << endl;

    cout << "-----------------------------------------" << endl;
    swap(&iv1, &iv2);                                   // 需要传入引用
    cout << "iv1\t\t = " << iv1 << endl;                // 值发生变化
    cout << "iv2\t\t = " << iv2 << endl;
    cout << "*pointer_1\t = " << *pointer_1 << endl;    // 值发生变化
    cout << "*pointer_2\t = " << *pointer_2 << endl;
    cout << "&iv1\t\t = " << &iv1 << endl;              // 地址不变
    cout << "&iv2\t\t = " << &iv2 << endl;
    cout << "pointer_1\t = " << pointer_1 << endl;      // 地址不变
    cout << "pointer_2\t = " << pointer_2 << endl;

    return 0;
}

void swap(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}