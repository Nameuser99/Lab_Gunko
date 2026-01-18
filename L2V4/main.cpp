#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

const int MAX = 100;

int main()
{
    double arr[MAX];
    int n;

    std::cout << "Enter n (1 <= n <= " << MAX << "): ";
    std::cin >> n;

    if (n < 1 || n > MAX) {
        std::cout << "Error: invalid n" << std::endl;
        return 0;
    }

    int choice;
    std::cout << "1 - keyboard, 2 - random: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter " << n << " numbers: ";
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
    }
    else if (choice == 2) {
        double a, b;
        std::cout << "Enter a b: ";
        std::cin >> a >> b;

        std::srand(static_cast<unsigned>(std::time(NULL)));

        for (int i = 0; i < n; ++i) {
            arr[i] = a + (b - a) * (std::rand() / static_cast<double>(RAND_MAX));
        }
    }
    else {
        std::cout << "Error: invalid choice" << std::endl;
        return 0;
    }

    std::cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    double min_val = arr[0];
    int min_index = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] <= min_val) {
            min_val = arr[i];
            min_index = i;
        }
    }
    std::cout << "Min index: " << min_index << std::endl;

    int first_neg = -1;
    int last_neg = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            if (first_neg == -1) {
                first_neg = i;
            }
            last_neg = i;
        }
    }

    double sum_between = 0.0;
    if (first_neg != -1 && first_neg != last_neg) {
        for (int i = first_neg + 1; i < last_neg; ++i) {
            sum_between += arr[i];
        }
        std::cout << "Sum between negatives: " << sum_between << std::endl;
    }
    else {
        std::cout << "Cannot compute sum: no or only one negative" << std::endl;
    }

    double X;
    std::cout << "Enter X: ";
    std::cin >> X;

    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (std::fabs(arr[i]) <= X) {
            double temp = arr[i];
            for (int k = i; k > j; --k) {
                arr[k] = arr[k - 1];
            }
            arr[j] = temp;
            ++j;
        }
    }

    std::cout << "Transformed array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

}