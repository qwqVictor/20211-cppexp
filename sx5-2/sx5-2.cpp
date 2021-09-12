#include <iostream>
#include <cstring>
#include <string>

char* xcat(char* string1, char* string2) {
    if (string1 == NULL || string2 == NULL)
        return NULL;
    int len1 = strlen(string1), len2 = strlen(string2), i = 0, j = 0;
    char* ret = new char[len1 + len2 + 1];
    for (i = 0, j = 0; i < len1 + len2; j++) {
        if (j < len1) ret[i++] = string1[j];
        if (j < len2) ret[i++] = string2[j];
    }
    ret[len1 + len2] = '\0';
    return ret;
}

char* xcat(const char* string1, const char* string2) {
    return xcat((char*)string1, (char*)string2);
}

int main(int argc, char const *argv[]) {
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    char* str = xcat(a.c_str(), b.c_str());
    std::cout << str << std::endl;
    delete[] str;
    return 0;
}
