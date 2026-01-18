#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 10;

int get_element(int** matrix, int i, int j) {
    return matrix[i][j];
}

void set_element(int** matrix, int i, int j, int value) {
    matrix[i][j] = value;
}

int main() {
    int m, cols;
    std::cout << "Enter m (1 <= m <= 5): ";
    std::cin >> m;
    if (m < 1 || m > 5) {
        std::cout << "Error: invalid m" << std::endl;
        return 0;
    }
    int rows = 2 * m;

    std::cout << "Enter number of columns (1 <= cols <= " << MAX_SIZE << "): ";
    std::cin >> cols;
    if (cols < 1 || cols > MAX_SIZE) {
        std::cout << "Error: invalid cols" << std::endl;
        return 0;
    }

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    int choice;
    std::cout << "1 - keyboard, 2 - random: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter first " << m << " rows (" << cols << " numbers each):" << std::endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < cols; ++j) {
                int val;
                std::cin >> val;
                set_element(matrix, i, j, val);
                set_element(matrix, i + m, j, val);
            }
        }
    } else if (choice == 2) {
        int a, b;
        std::cout << "Enter a b for random ints: ";
        std::cin >> a >> b;
        if (a > b) {
            std::cout << "Error: a > b" << std::endl;
            return 0;
        }
        std::srand(static_cast<unsigned>(std::time(NULL)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < cols; ++j) {
                int val = a + std::rand() % (b - a + 1);
                set_element(matrix, i, j, val);
                set_element(matrix, i + m, j, val);
            }
        }
    } else {
        std::cout << "Error: invalid choice" << std::endl;
        return 0;
    }

    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << get_element(matrix, i, j) << " ";
        }
        std::cout << std::endl;
    }

    int no_zero_cols = 0;
    for (int j = 0; j < cols; ++j) {
        bool has_zero = false;
        for (int i = 0; i < rows; ++i) {
            if (get_element(matrix, i, j) == 0) {
                has_zero = true;
                break;
            }
        }
        if (!has_zero) {
            ++no_zero_cols;
        }
    }
    std::cout << "Columns without zeros: " << no_zero_cols << std::endl;

    int max_len = 0;
    int first_row_with_max = -1;
    for (int i = 0; i < rows; ++i) {
        int current_len = 1;
        int max_in_row = 1;
        for (int j = 1; j < cols; ++j) {
            if (get_element(matrix, i, j) > get_element(matrix, i, j - 1)) {
                ++current_len;
            } else {
                if (current_len > max_in_row) {
                    max_in_row = current_len;
                }
                current_len = 1;
            }
        }
        if (current_len > max_in_row) {
            max_in_row = current_len;
        }
        if (max_in_row > max_len) {
            max_len = max_in_row;
            first_row_with_max = i;
        }
    }
    if (first_row_with_max != -1) {
        std::cout << "First row with longest increasing sequence: " << first_row_with_max << std::endl;
    } else {
        std::cout << "No rows with increasing sequences" << std::endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}