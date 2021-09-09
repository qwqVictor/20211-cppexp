/** FILENAME: calculation.h **/

void funcWait();
void funcSum();
void funcAvg();
void funcVar();
void funcEquation();

/** FILENAME: calculation.cpp **/
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstdio>
// #include "calculation.h"
#ifdef WIN32
    #define clearScreen() (system("cls"))
#else
    #define clearScreen() (system("clear"))
#endif

const double EPS = 1e-10;

int main(int argc, char const *argv[]) {
BEGIN:
    clearScreen();
    std::cerr << "Enter a number to select in the menu shown below:\n\
    - 0. Exit \n\
    - 1. Calculate Sum \n\
    - 2. Calculate Average \n\
    - 3. Calculate Variance \n\
    - 4. Solve Quadratic Equation \n\
Number: ";
    int n;
    std::cin >> n;
    if (std::cin.eof()) n = 0;
    if (getchar() == '\r') getchar();
    switch (n) {
        case 0:
            std::cerr << "Exiting!" << std::endl;
            goto EXIT;
            break;
        case 1:
            funcSum();
            break;
        case 2:
            funcAvg();
            break;
        case 3:
            funcVar();
            break;
        case 4:
            funcEquation();
            break;
        default:
            std::cerr << "Please input number in range [0, 3]!" << std::endl;
            break;
    }
    funcWait();
    goto BEGIN;
EXIT:
    return 0;
}

std::vector<double> readNumbers() {
    std::vector<double> ret;
    std::cerr << "Input a line of number separated by space below:" << std::endl;
    std::string buf = "";
    std::getline(std::cin, buf);
    std::stringstream str(buf);
    double tmp;
    while (true) {
        str >> tmp;
        ret.push_back(tmp);
        if (str.eof()) break;
    }
    return ret;
}

double getSum(std::vector<double> numbers) {
    double sum = 0;
    for (std::vector<double>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        sum += *it;
    }
    return sum;
}

double getAverage(std::vector<double> numbers) {
    double sum = getSum(numbers);
    return sum / numbers.size();
}

double getVariance(std::vector<double> numbers) {
    double average = getAverage(numbers);
    int n = numbers.size();
    double var = 0;
    for (std::vector<double>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        var += (average - *it) * (average - *it);
    }
    var /= n;
    return var;
}

void funcWait() {
#ifdef WIN32
    system("pause")
#else
    std::cerr << "Press enter to continue..." << std::endl;
    getchar();
#endif
}

void funcSum() {
    std::vector<double> numbers = readNumbers();
    std::cout << "Sum: " << getSum(numbers) << std::endl;
}

void funcAvg() {
    std::vector<double> numbers = readNumbers();
    std::cout << "Average: " << getAverage(numbers) << std::endl;
}

void funcVar() {
    std::vector<double> numbers = readNumbers();
    std::cout << "Variance: " << getVariance(numbers) << std::endl;
}

inline double delta(double a, double b, double c) { return b * b - 4 * a * c; }
void funcEquation() {
    double a = 0, b = 0, c = 0;
    std::vector<double> solutions;
    std::cerr << "Input the a, b, c of ax^2+bx+c=0: " << std::endl;
    std::cin >> a >> b >> c;
    if (getchar() == '\r') getchar();
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
    return;
}