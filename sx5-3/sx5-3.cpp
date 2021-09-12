#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

std::pair<int, int> findChar(char* source, char ch) {
    int pos = -1, freq = 0, len = strlen(source);
    for (int i = 0; i < len; i++)
        if (source[i] == ch) {
            if (pos == -1) pos = i;
            freq++;
        }
    return std::make_pair(pos, freq);
}

std::pair<int, int> findChar(const char* source, char ch) {
    return findChar((char*)source, ch);
}

int main(int argc, char const *argv[]) {
    std::string source;
    char ch;
    std::getline(std::cin, source);
    std::cin >> ch;
    std::pair<int, int> result = findChar(source.c_str(), ch);
    std::cout << "First occurence is at " << result.first << ", in total " << result.second << " occurences." << std::endl;
    return 0;
}