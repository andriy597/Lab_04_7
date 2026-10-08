// Лабораторна робота № 4
// Варіант 14

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;

    cout << "xp = ";  cin >> xp;
    cout << "xk = ";  cin >> xk;
    cout << "dx = ";  cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "      |"
        << setw(10) << "cos(x)" << "   |"
        << setw(7) << "S" << "       |"
        << setw(5) << "n" << "   |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        n = 0;                      // номер доданка
        a = 1;                      // перший доданок: (-1)^0 x^0 / 0! = 1
        S = a;
        do {
            n++;
            R = -x * x / ((2. * n - 1) * (2. * n));   // коефіцієнт рекурентності
            a *= R;
            S += a;
        } while (fabs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x << "    |"
            << setw(10) << setprecision(5) << cos(x) << "    |"
            << setw(10) << setprecision(5) << S << "    |"
            << setw(5) << n << "    |"
            << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}