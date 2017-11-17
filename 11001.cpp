#include <iostream>
#include <cmath>
using namespace std;

double vt, v0;

double d(double v)
{
    return 0.3 * sqrt(v - v0);
}

int main()
{
    while (cin >> vt >> v0, vt || v0)
    {
        double m = 0; int k = 0;
        for (int i = 1; vt / i > v0; ++i)
        {
            double nm = i * d(vt / i);
            if (nm - 1e-7 > m)
            {
                m = nm;
                k = i;
            }
            else if (abs(nm - m) < 1e-7)
                k = 0;
        }
        cout << k << '\n';
    }
}
