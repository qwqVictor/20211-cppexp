#include <iostream>
#include <tuple>
#include <vector>
#include <cstdint>

void printColors(int8_t a, int8_t b, int8_t c) {
    static const char* colors[] = {"", "Red", "Yellow", "Blue", "White", "Black"};  // mapping index to color
    std::cout << "Ball 1: " << colors[a] << "\t" << "Ball 2: " << colors[b] << "\t" << "Ball 3: " << colors[c] << std::endl;
}

int main() {
    int8_t n = 0;      // count of conditions
    std::vector<std::tuple<int8_t, int8_t, int8_t> > conditions; // store conditions with tuple
    for (int8_t i = 1; i <= 5; i++) {
        for (int8_t j = 1; j <= 5; j++) {
            for (int8_t k = 1; k <= 5; k++) {
                if ((i != j) && (i != k) && (j != k)) { // if colors are different
                    n++;
                    conditions.push_back({i, j, k});    // store conditions
                }
            }
        }
    }
    std::cout << "Count of conditions: " << +n << std::endl;
    for (std::vector<std::tuple<int8_t, int8_t, int8_t> >::iterator it = conditions.begin(); it != conditions.end(); it++) {
        printColors(std::get<0>(*it), std::get<1>(*it), std::get<2>(*it));  // print8_t colors from tuple
    }
}