#include <iostream>
#include <fstream>

const int MAX_LINE = 1024;
const int MAX_NAME = 256;

int main() {
    char in_name[MAX_NAME];
    char out1_name[MAX_NAME];
    char out2_name[MAX_NAME];
    std::cout << "Enter input file name: ";
    std::cin >> in_name;
    std::cout << "Enter first output file name: ";
    std::cin >> out1_name;
    std::cout << "Enter second output file name: ";
    std::cin >> out2_name;

    std::ifstream in(in_name);
    if (!in) {
        std::cout << "Error opening input file" << std::endl;
        return 0;
    }

    std::ofstream out1(out1_name);
    std::ofstream out2(out2_name);

    char show;
    std::cout << "Show input file content? (y/n): ";
    std::cin >> show;
    if (show == 'y') {
        char line[MAX_LINE];
        in.seekg(0);
        while (in.getline(line, MAX_LINE)) {
            std::cout << line << std::endl;
        }
        in.clear();
        in.seekg(0);
    }

    char line[MAX_LINE];
    while (in.getline(line, MAX_LINE)) {
        bool non_dec = true;
        bool non_inc = true;
        int i = 1;
        while (line[i] != '\0') {
            if (line[i] < line[i - 1]) {
                non_dec = false;
            }
            if (line[i] > line[i - 1]) {
                non_inc = false;
            }
            ++i;
        }
        if (non_dec) {
            out1 << line << std::endl;
        }
        if (non_inc) {
            out2 << line << std::endl;
        }
    }

    in.close();
    out1.close();
    out2.close();

    std::cout << "Show first output file? (y/n): ";
    std::cin >> show;
    if (show == 'y') {
        std::ifstream out1_show(out1_name);
        while (out1_show.getline(line, MAX_LINE)) {
            std::cout << line << std::endl;
        }
        out1_show.close();
    }

    std::cout << "Show second output file? (y/n): ";
    std::cin >> show;
    if (show == 'y') {
        std::ifstream out2_show(out2_name);
        while (out2_show.getline(line, MAX_LINE)) {
            std::cout << line << std::endl;
        }
        out2_show.close();
    }
}