#include <iostream>
#include <cstdio>
#include <string>

int main() {
    while (true) {
        std::cerr << "Please enter a formula of two integers with (+ - * /):" << std::endl;
        double num1 = 0, num2 = 0, result = 0;
        char op;                // the operator
        std::cin >> num1 >> op >> num2;
        bool error = false;     // record if any errors exists
        if ((num1 == 0) && (num2 == 0)) // if num1 or num2 is zero
            break;
        switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cerr << "Can't be divided by zero!" << std::endl;
                error = true;
                break;
            }
            result = num1 / num2;
            break;
        default:
            std::cerr << "Invalid operator!" << std::endl;
            break;
        }
        if (!error) {       // if any error exists, don't output
            std::cout << num1 << op << num2 << "=" << result << std::endl;
        }
    }
    return 0;
}