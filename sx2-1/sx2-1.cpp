#include <iostream>
#include <cmath>

double a(int i) {
    return 1.0 / (2 * i - 1) - 1.0 / (2 * i);
}

int main(int argc, char const *argv[]) {
    double eps = 1e-5;
    if (argc > 1) {
        sscanf(argv[1], "%lf", &eps);
    }
    double sum = 0, a_n = 1;
    for (int i = 1; a_n > eps; i++) {
        a_n = a(i);
        sum += a_n;
    }
    std::cout << "calculated ln2: \t" << sum << std::endl;
    std::cout << "standard ln2: \t" << log(2) << std::endl;
    return 0;
}