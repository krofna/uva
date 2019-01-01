#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cout << setprecision(3) << fixed;
    for (int u = 1; u <= t; ++u)
    {
        int d, v, w;
        cin >> d >> v >> w;
        cout << "Case " << u << ": ";
        if (w > v && v)
        {
            float a = (float)d / w, b = d / sqrt(w * w - v * v);
            cout << b - a << '\n';
        }
        else
            cout << "can't determine\n";
    }
}
