#include <iostream>
#include <iomanip>
#include <cstring>
using std::cout;
using std::endl;
using std::setw;

int* multiplication(int* a, int arow, int acol, int* b, int brow, int bcol) {
    if (acol != brow) return NULL;
    int row = arow, col = bcol;
    int* c = new int[row * col];
    memset(c, 0, row * col * sizeof(int));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            c[col * i + j] = 0;
            for (int k = 0; k < acol; k++) {
                c[col * i + j] += a[acol * i + k] * b[bcol * k + j];
            }
        }
    }
    return c;
}

void print(int* c, int crow, int ccol) {
    for (int i = 0; i < crow; i++) {
        for (int j = 0; j < ccol; j++) {
            cout << setw(5) << c[crow * i + j];
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    const int arow = 3, acol = 4;
    int a[arow][acol] = {
        { 5, 7, 8, 2 },
        { -2, 4, 1, 1 },
        { 1, 2, 3, 4 }
    };

    const int brow = 4, bcol = 5;
    int b[brow][bcol] = {
        { 4, -2, 3, 3, 9 },
        { 4, 3, 8, -1, 2 },
        { 2, 3, 5, 2, 7 },
        { 1, 0, 6, 3, 4 }
    };

    const int crow = 3, ccol = 5;
    int* c = multiplication((int*)a, arow, acol, (int*)b, brow, bcol);
    if (c != NULL) {
        print(c, crow, ccol);
    }
    delete[] c;
    return 0;
}
