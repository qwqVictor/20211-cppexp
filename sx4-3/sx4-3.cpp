#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    int size = n > m ? n : m;
    int *matrix;
    matrix = new int[size * size];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i * size + j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i * size + j) != (j * size + i)) {
                matrix[i * size + j] ^= matrix[j * size + i];
                matrix[j * size + i] ^= matrix[i * size + j];
                matrix[i * size + j] ^= matrix[j * size + i];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(5) << matrix[i * size + j];
        }
        std::cout << std::endl;
    }
    delete[] matrix;
    return 0;
}