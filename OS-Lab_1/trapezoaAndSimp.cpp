#include <iostream>
#include <cmath>
using namespace std;

// Example function: f(x) = x^2 + 1
double f(double x) {
    return x * x + 1;
}

// Trapezoidal Rule implementation
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double sum = (f(a) + f(b)) / 2;  // half-weight for endpoints

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);  // add middle terms normally
    }

    return h * sum;
}

// Simpson’s 1/3 Rule implementation
double simpson(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "⚠️ Error: n must be even for Simpson's rule.\n";
        return NAN;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;

        if (i % 2 == 0)
            sum += 2 * f(x);   // even terms
        else
            sum += 4 * f(x);   // odd terms
    }

    return (h / 3) * sum;
}

// Simpson's 3/8 Rule implementation
double simpson38(double a, double b, int n) {
    if (n % 3 != 0) {
        cout << "⚠️ Error: n must be a multiple of 3 for Simpson's 3/8 rule.\n";
        return NAN;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;

        if (i % 3 == 0)
            sum += 2 * f(x);  // every 3rd term
        else
            sum += 3 * f(x);  // others
    }

    return (3 * h / 8) * sum;
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (n): ";
    cin >> n;

    cout << fixed;
    cout.precision(6);

    double trap = trapezoidal(a, b, n);
    double simp = simpson(a, b, n);

    cout << "\nTrapezoidal Rule Result: " << trap;
    if (!isnan(simp))
        cout << "\nSimpson's 1/3 Rule Result: " << simp << endl;

    return 0;
}
