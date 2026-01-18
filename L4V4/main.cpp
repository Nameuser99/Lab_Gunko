#include <iostream>

const int MAX_LEN = 301;

char* my_strcpy(char* dest, const char* src) {
    char* p = dest;
    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';
    return p;
}

int main() {
    std::cout << "Demonstration of my_strcpy:\n";
    char buf[100];
    my_strcpy(buf, "Test string copy");
    std::cout << "Copied string: " << buf << std::endl;

    std::cout << "\nTask B - Enter string (max 300 chars): ";
    char str[MAX_LEN];
    std::cin.getline(str, MAX_LEN);

    char* found_start = nullptr;
    int found_len = 0;

    int i = 0;
    while (str[i] != '\0') {
        // Skip spaces
        while (str[i] == ' ' && str[i] != '\0') {
            ++i;
        }
        if (str[i] == '\0') {
            break;
        }

        char* start = &str[i];
        while (str[i] != ' ' && str[i] != '\0') {
            ++i;
        }
        char* end = &str[i];

        // Check strictly increasing codes
        bool good = true;
        for (char* p = start + 1; p < end; ++p) {
            if (*p <= *(p - 1)) {
                good = false;
                break;
            }
        }

        if (good) {
            found_start = start;
            found_len = static_cast<int>(end - start);
            break; // First one
        }
    }

    if (found_start != nullptr && found_len > 0) {
        std::cout << "Found word: ";
        for (int k = 0; k < found_len; ++k) {
            std::cout << found_start[k];
        }
        std::cout << std::endl;
    } else {
        std::cout << "No such word" << std::endl;
    }
}