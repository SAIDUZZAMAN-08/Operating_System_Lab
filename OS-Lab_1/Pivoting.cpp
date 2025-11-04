#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

vector<double> gaussianElimination(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    // Forward elimination with partial pivoting
    for (int i = 0; i < n - 1; i++) {
        // Find the pivot row (max absolute value in current column)
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(A[k][i]) > fabs(A[maxRow][i])) {
                maxRow = k;
            }
        }

        // Swap rows in A and b if needed
        if (maxRow != i) {
            swap(A[i], A[maxRow]);
            swap(b[i], b[maxRow]);
        }

        // Check if pivot is zero after swap
        if (fabs(A[i][i]) < 1e-9) {
            cerr << "Error: Zero pivot encountered!" << endl;
            exit(1);
        }

        // Eliminate elements below pivot
        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Back substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    return x;
}

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter coefficients of matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter constants vector b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<double> solution = gaussianElimination(A, b);

    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << solution[i] << endl;
}

