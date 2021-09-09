#include <iostream>
#include <cmath>
#include <vector>
const double EPS = 1e-7;

double delta(double a, double b, double c) {
    return b * b - 4 * a * c;
}

int main(int argc, char const *argv[]) {
    double a = 0, b = 0, c = 0;
    std::vector<double> solutions;
    std::cerr << "Input the a, b, c of ax^2+bx+c=0: " << std::endl;
    std::cin >> a >> b >> c;
    if (a == 0) {
        if (b != 0)
            solutions.push_back(-c / b);
    }
    else {
        double d = delta(a, b, c);
        if (d > EPS) {
            solutions.push_back((-b + sqrt(d)) / (2 * a));
            solutions.push_back((-b - sqrt(d)) / (2 * a));
        }
        else if (d < -EPS) {}
        else {
            solutions.push_back((-b) / (2 * a));
        }
    }
    if (solutions.empty()) {
        std::cerr << "No solution." << std::endl;
    }
    else {
        for (std::vector<double>::iterator it = solutions.begin(); it != solutions.end(); it++) {
            std::cout << "x = " << *it << std::endl;
        }
    }
#ifdef WIN32
    system("pause")
#endif
    return 0;
}