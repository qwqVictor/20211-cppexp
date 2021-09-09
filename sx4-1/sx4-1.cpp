#include <iostream>
using std::cout;
using std::endl;

int main() {
    int ia1[3];
    cout << ia1 << endl;                            // 数组 ia1 首地址，即 0 号元素(第一个元素)的地址
    cout << ia1 + 1 << endl;                        // 数组 ia1 1 号元素(第二个元素)的地址
    cout << &ia1[0] + 1 << endl;                    // 数组 ia1 1 号元素的地址
    cout << &ia1[0] + 1 * sizeof(int) << endl;      // 数组 ia1 偏移 1 * sizeof(int) = 4，即 4 号元素的地址
    cout << &ia1[1] << endl << endl;                // 数组 ia1 1 号元素(第二个元素)的地址

    int ia2[3][3];
    cout << ia2 << endl;                                        // 二维数组 ia2 首地址，也是 ia2[0] 数组首地址
    cout << ia2 + 0 * 3 + 1 << endl;                            // 二维数组 ia2 偏移一个子数组长度的地址，即偏移 3 * sizeof(int) = 12
    cout << ia2[0] + 0 * 3 + 1 << endl;                         // 二维数组 ia2 第一个子数组的 1 号元素的地址，偏移 0 + 1 * sizeof(int) = 4
    cout << &ia2[0][0] + (0 * 3 + 1) * sizeof(int) << endl;     // 二维数组 ia2 偏移 sizeof(int) * (1 * sizeof(int)) = 16
    cout << &ia2[0][0] + (0 * 3 + 1) * 4 << endl;               // 二维数组 ia2 1 号元素(第二个元素)的地址
    cout << &ia2[0][0] + 0 * 3 + 1 << endl;                     // 二维数组 ia2 1 号元素(第二个元素)的地址
    cout << &ia2[0][1] << endl << endl;                         // 二维数组 ia2 1 号元素(第二个元素)的地址

    int ia3[3][3][3];
    cout << ia3 << endl;                                        // 三维数组 ia3 首地址
    cout << ia3 + 0 * 3 * 3 + 0 * 3 + 1 << endl;                // ia3 偏移一个 int[3][3] 的长度，即 3 * 3 * sizeof(int) = 36
    cout << ia3[0] + 0 * 3 * 3 + 0 * 3 + 1 << endl;             // ia3 偏移一个 int[3] 的长度，即 3 * sizeof(int) = 12
    cout << ia3[0][0] + 0 * 3 * 3 + 0 * 3 + 1 << endl;          // ia3 偏移一个 int 的长度，即 sizeof(int) = 4
    cout << &ia3[0][0][0] + (0 * 3 * 3 + 0 * 3 + 1) * sizeof(int) << endl;  // ia3 偏移 sizeof(int) * (1 * sizeof(int)) = 16，即 &ia3[0][0][4]
    cout << &ia3[0][0][0] + 0 * 3 * 3 + 0 * 3 + 1 << endl;      // ia3 偏移一个 int 的长度，即 sizeof(int) = 4
    cout << &ia3[0][0][1] << endl << endl;                      // ia3 偏移 1 * sizeof(int) = 4，即 &ia3[0][0][4]
    return 0;
}