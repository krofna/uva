#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int p, q, r, s, t, u;

double eq(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bs()
{
    double x, a = 0, b = 1;
    while (fabs(b - a) > 1e-9)
    {
        x = (a + b) / 2;
        if (eq(x) > 0)
            a = x;
        else
            b = x;
    }
    return x;
}

int main()
{
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        if (eq(1) > 0.0 || eq(0) < 0.0)
            cout << "No solution\n";
        else
            cout << fixed << setprecision(4) << bs() << '\n';
    }
}
