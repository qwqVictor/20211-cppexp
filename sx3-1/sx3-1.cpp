#include <iostream>

double power(double x, int n) {
    double ans = 1;
    if (!n) return x;
    x = n < 0 ? (1.0 / x) : x;
    n = n < 0 ? -n : n;
    while (n >>= 1) {
        x = x * x;
        if (n & 1) ans = ans * x;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    double base;
    int expo;
    std::cin >> base >> expo;
    std::cout << power(base, expo) << std::endl;
    return 0;
}