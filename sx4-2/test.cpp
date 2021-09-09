#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

const int arow = 3, acol = 4;
int a[arow][acol] = {
    { 5, 7, 8, 2 },
    { -2, 4, 1, 1 },
    {1, 2, 3, 4}
};

const int brow = 4, bcol = 5;
int b[brow][bcol] = {
    { 4, -2, 3, 3, 9 },
    { 4, 3, 8, -1, 2 },
    { 2, 3, 5, 2, 7 },
    { 1, 0, 6, 3, 4 }
};

const int crow = 3, ccol = 5;
int c[crow][ccol];

int** multiplication(int** a, int arow, int acol, int** b, int brow, int bcol) {
    if (arow != bcol) return NULL;
    int** c = new int*[arow];
    for (int i = 0; i < arow; i++) c[i] = new int[bcol];
    for (int i = 0; i < crow; i++) {
        for (int j = 0; j < ccol; j++) {
            c[i][j] = 0;
            for (int k = 0; k < acol; k++) {
                for (int k = 0; k < acol; k++)
                    c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

void print(int* c, int crow, int ccol) {

}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < crow; i++) {
        for (int j = 0; j < ccol; j++) {
            c[i][j] = 0;
            for (int k = 0; k < acol; k++) {
                if (i == 0 && j == 0)
                    fprintf(stderr, "a_%d%d(%d) * b_%d%d(%d) = %d\n", i, k, a[i][k], k, j, b[k][j], a[i][k] * b[k][j]);
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < crow; i++) {
        for (int j = 0; j < ccol; j++) {
            cout << setw(5) << c[i][j];
        }
        cout << endl;
    }
    return 0;
}

