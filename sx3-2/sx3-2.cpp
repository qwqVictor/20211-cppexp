#include <iostream>
#include <cstring>
#include <cassert>

int recursive(int day = 10, int peach = 1) {
    assert(day > 0 && day <= 10);
    if (day == 1)
        return peach;
    else
        return recursive(day - 1, (peach + 1) * 2);
}

int non_recursive(int day = 10) {
    int i, *peaches = new int[day], ret;
    for (i = 1, peaches[0] = 1; i < day; i++)
        peaches[i] = (peaches[i - 1] + 1) * 2;
    ret = peaches[day - 1];
    delete[] peaches;
    return ret;
}

int main(int argc, char const *argv[]) {
    std::cout << "Calculated peaches on day 1 by..." << std::endl;
    std::cout << "Non-Recursive function: " << non_recursive() << std::endl;
    std::cout << "Recursive function: " << recursive() << std::endl;
    std::cout << "If on day 4 there's 1 peach remaining, day 1: " << recursive(4) << " (by recursive)." << std::endl;
    std::cout << "If on day 4 there's 1 peach remaining, day 2: " << non_recursive(4) << " (by non-recursive)." << std::endl;
    return 0;
}