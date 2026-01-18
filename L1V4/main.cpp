#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double x;
    int k;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter k (>1): ";
    cin >> k;
    
    if (k <= 1) {
        cout << "Error: k must be >1" << endl;
        return 0;
    }
    
    if (x < -1.0 || x >= 1.0) {
        cout << "Error: x not in [-1, 1)" << endl;
        return 0;
    }
    
    const double eps = 1e-6;
    double sum = 0.0;
    double term = -x;
    int n = 1;
    double current_pow = x;
    
    while (fabs(term) >= eps) {
        sum += term;
        n++;
        current_pow *= x;
        term = -current_pow / n;
    }
    
    double exact = log(1.0 - x);
    
    cout << fixed << setprecision(k);
    cout << "Approximate value: " << sum << endl;
    cout << "Exact value: " << exact << endl;
    cout << "Number of terms: " << n << endl;
    
}