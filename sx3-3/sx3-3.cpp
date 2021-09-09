#include <iostream>
#include <cstring>
#include <cassert>

int recursive(int day = 10, int peach = 1) {
    int deferrer;
    assert(day > 0 && day <= 10);
    if (day == 1) {
        deferrer = peach; goto defer;
    }
    else {
        deferrer = recursive(day - 1, (peach + 1) * 2); goto defer;
    }
defer:
    std::cout << peach << ",";
    return deferrer;
}

int non_recursive(int day = 10) {
    int i, *peaches = new int[day], ret;
    for (i = 1, peaches[0] = 1; i < day; i++)
        peaches[i] = (peaches[i - 1] + 1) * 2;
    ret = peaches[day - 1];
    for (int i = day; i > 0; i--) {
        std::cout << peaches[i - 1] << ",";
    }
    delete[] peaches;
    return ret;
}

int main(int argc, char const *argv[]) {
    int n;
    std::cerr << "On which day there's only 1 peach remaining: ";
    std::cin >> n;
    std::cout << "Calculated peaches on day 1 by..." << std::endl;
    std::cout << "Recursive function:\tlist[";
    int rec = recursive(n);
    std::cout << "\b], answer: " << rec << std::endl;

    std::cout << "Non-Recursive function:\tlist[";
    int nrec = non_recursive(n);
    std::cout << "\b], answer: " << nrec << std::endl;
    return 0;
}
